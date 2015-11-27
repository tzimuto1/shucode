#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

#include "huffman_util.h"
#include "compression_util.h"
#include "data.h"

#define SUCCESS           0
#define ERR_BUFF_SIZE     256
#define SYMBOL_SIZE       5
#define NMATCH            1

char ERR_BUFF[ERR_BUFF_SIZE];

/*
 * Return the position of character c in the custom alphabet. The custom alphabet
 * is a listing of ASCII printable chars
 */
static int get_alphabet_pos(char c)
{
    switch (c)
    {
    case '\t':
	return 0;
    case '\n':
	return 1;
    case '\r':
	return 2;
    default:
	return c - 32 + 3;
    }
}

static int node_compare(const void *v1, const void *v2)
{
    char *symbol = (char *) v1;
    node *node_p = (node *) v2;
#ifdef DEBUG
    printf("Function:%s, v1:%s, v2:%s\n", __func__, symbol, node_p->symbol);
#endif
    return strcmp(symbol, node_p->symbol);
}

/*
 * Return a node mapped to symbol
 * @param symbol - either printable character or one of Shona's syllables 
 */
static node *get_node(char * symbol)
{
    char  c = symbol[0];
    int   alphabet_pos;
    const int *range;
    int   max, min, nmemb;
    node  *base;
    
    alphabet_pos = get_alphabet_pos(c);
    range        = printable_char_ranges[alphabet_pos];
    min          = range[0], max = range[1];
    nmemb        = max - min + 1;
    base         = &node_list[min];
#ifdef DEBUG
    printf("Symbol:%s, Position:%i, Max:%i, Min:%i, Base:%s, Nmemb:%i\n", symbol, alphabet_pos, max, min, base->symbol, nmemb);
#endif
    //there is only one syllable that starts with symbol[0]
    if (nmemb == 1)
	return &node_list[min];
    return (node *) bsearch(symbol, base, nmemb, sizeof(node), node_compare);
}


static void file_data_free(file_data *fd)
{
    free(fd->list);
    free(fd);
}

/* 
 * Update the nodes with frequence values and initilizalize a structure containing the file data
 * The file data lists all the supported symbols in the order that they were found in the file
 * The data is used during the actual compression stage (see compression_util.c)
 */
static file_data *process_input(char *file)
{
    FILE    *fp    = fopen(file, "r");
    char    *line  = NULL;
    char    *line_cpy;
    size_t  n      = 0;
    ssize_t read;
    int     status;
    regex_t compiled_regex;
    file_data *fd  = (file_data *) malloc(sizeof(file_data)); 

    //initalize the input file data. Ugh, memory penalty!
    fd->num_alloced = 10;
    fd->num_elem    = 0;
    fd->list        = (node **) malloc(sizeof(node *) * fd->num_alloced);

    //now file processing: scanning for all Shona syllables/symbols
    status = regcomp(&compiled_regex, shona_regex, REG_EXTENDED);
    
    if (status != SUCCESS)
    {
	regerror(status, &compiled_regex, ERR_BUFF, ERR_BUFF_SIZE);
	goto error;
    }
    
    if (fp == NULL)
    {
	sprintf(ERR_BUFF, "Could not open the file\n");
	goto error;
    }
    
    while ((read = getline(&line, &n, fp)) != -1)
    {
	line_cpy = line;
	//process the line and input into the data structure
        while (1)
        {
	    size_t     nmatch           = NMATCH;
	    regmatch_t matchptr[NMATCH];
	    int        c_flag           = 0;
	    int        status = regexec(&compiled_regex, line_cpy, nmatch, matchptr, c_flag);
	    
	    
	    if (status == SUCCESS)
	    {
		int   start = matchptr[0].rm_so;
		int   end   = matchptr[0].rm_eo;
		int   width = end - start;
		char  symbol[SYMBOL_SIZE];
		node  *symbl_node;
		
		sprintf(symbol, "%.*s", width, line_cpy + start);
		symbl_node = get_node(symbol);
		
		if (!symbl_node)
		{
		    sprintf(ERR_BUFF, "Could not find node: %s, AlphabetPos: %i\n", symbol, get_alphabet_pos(symbol[0]));
		    goto error;
		}

		//upadate the data structures
		symbl_node->freq++;
		symbl_node->in_file = 1;
		line_cpy += end;

		fd->list[fd->num_elem++] = symbl_node;

		if (fd->num_elem == fd->num_alloced)
		{
		    fd->num_alloced += 10;
		    node **temp_list = (node **) realloc(fd->list, sizeof(node *) * fd->num_alloced);
		    
		    if (!temp_list)
		    {
			sprintf(ERR_BUFF, "Memory error\n");
			goto error;
		    }
		    
		    fd->list = temp_list;
		}
	    }
	    else if (status == REG_NOMATCH)
	    {
		//coninue to the next line
		break;
	    }
	    else
	    {
		regerror(status, &compiled_regex, ERR_BUFF, ERR_BUFF_SIZE);
		goto error;
	    }
	}//while(1)
    }//while(line to read)

    free(line);
    fclose(fp);
    regfree(&compiled_regex);
    return fd;

error:
    printf(ERR_BUFF);
    free(line);
    fclose(fp);
    file_data_free(fd);
    regfree(&compiled_regex);
    exit(EXIT_FAILURE);
}


#ifndef TEST_MODE
void main(int argc, char *argv[])
{
    //TODO write proper interface
    if (argc < 2)
    {
	printf("Missing arguments");
	return;
    }
    
    //currently process only one file
    char      *file = argv[1];
    char      *dest_file;
    char      *ext = ".sc";
    file_data *fd = process_input(file);
    node      *huff_nodes[NODE_COUNT];

    dest_file = (char *) calloc(sizeof(char), strlen(file) + strlen(ext) + 1);
    sprintf(dest_file, "%s%s", file, ext);
    
    //filter out nodes for huffman processing
    int i, j = 0;
    for (i = 0; i < NODE_COUNT; i++)
    {
	if (node_list[i].in_file)
	{
	    huff_nodes[j++] = node_list + i;
	}
    }
	
    get_codebook(huff_nodes, j);
    
    compress_file(fd, node_list, NODE_COUNT, dest_file);

    free(dest_file);
    free(fd->list);
    free(fd);
    return;
}
#endif
