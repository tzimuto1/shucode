#include "data.h"
#include <stdio.h>
#include <stdlib.h>
//#define DEBUG

#ifdef  DEBUG
#define PRINT(format, ...) printf(format, ## __VA_ARGS__)
#else
#define PRINT(format, ...)   //
#endif

/*
  Below is the structure of the file that will be created by this library:

  [num_codes | code_book | codes | padding]
  -code_book is a sequence of code lengths corresponding to each of the Shona symbols. Currently 4 bytes are used to represent the lengths.  This is a limitation of the program. We can't represent codes that need more than 32 bits. That implies that the huffman tree must not
  have a depth of more than 32 or else the data gets corrupted.
  -codes is the output of encoding the symbols in the input file.
  -num_codes is the number of symbols encoded i.e the file size when using Shona syllables as the atomic units instead of individual chars.  It is represented by 32 bits. So this program can't work for super big files more than half a gigabyte. TODO: change this to 64 bits so that larger files can be compressed
  -padding is the sequence of bits added to the file inorder to form an integral number of bytes.
 */


int compress_file(file_data *fd, node *codebook, int cb_len, char *dest_file)
{
    FILE *fp = fopen(dest_file, "w");
    uint32_t i, l;
    unsigned char c;

    if (fp == NULL)
    {
	perror("Error encountered");
	return 0;
    }
    
    //append the length
    uint32_t num_codes = fd->num_elem;
    fwrite(&num_codes, sizeof(num_codes), 1, fp);
   
    //append the code book
    for (i = 0; i < cb_len; i++)
    {
	l = codebook[i].nbits;
        //TODO this should be captured in the huffman_util instead of here. We don't want to unnecessarily waste cycles
	if (l > 32)
	{
	    printf("Failure length long");
	    exit(1);
	}
	
	fwrite(&l, sizeof(uint32_t), 1, fp);
    }

    //append the codes
    node *np;
    int  cur_len = 0, cur_val = 0, code_len = 0, code_val = 0, total_len = 0, total_val = 0;
    
    for (i = 0; i < fd->num_elem; i++)
    {
	np = fd->list[i];
	code_len = np->nbits;
	code_val = np->code;
        total_len = cur_len + code_len;
	
	if (total_len < 8)
	{
	    cur_val = cur_val + (code_val << (8 - cur_len - code_len));
	    cur_len = cur_len + code_len;
	    PRINT("Len < 8, cur_val: %i, cur_len: %i, total_len: %i\n", cur_val, cur_len, total_len);
	}
	else
	{
	    total_val = cur_val + (code_val >> (code_len + cur_len - 8));
	    c = total_val;
	    fwrite(&c, sizeof(char), 1, fp);
	    int mask = (1 << (code_len + cur_len - 8)) -1;
	    cur_len  = code_len + cur_len - 8;
	    cur_val  = (code_val & mask);
	    
	    while (cur_len >= 8)
	    {
		c = cur_val >> (cur_len - 8);
		fwrite(&c, sizeof(char), 1, fp);
		mask = (1 << (cur_len - 8)) - 1;
		cur_len = (cur_len - 8);
		cur_val = cur_val & mask;
		PRINT("Len > 8, cur_val: %i, cur_len: %i, total_val: %i, total_len: %i. code_val: %i\n", cur_val, cur_len, c, total_len, code_val);
	    }
	    
	    cur_val = (cur_val) << (8 - cur_len);
	}
    }

    //append the padding
    if (cur_len > 0)
    {
	c = cur_val;
	fwrite(&c, sizeof(char), 1, fp);
    }

    //clean up
    fclose(fp);

    return 1;
}

