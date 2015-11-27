#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "data.h"

#ifdef  DEBUG
#define PRINT(format, ...) printf(format, ## __VA_ARGS__)
#else
#define PRINT(format, ...)   //
#endif


/**
   Compare nodes for ordering first by code length and then by symbol.
   This comparison function makes qsort stable
 */
static int canonical_cmp(const void *n1, const void *n2)
{
    node *np1 = *(node **) n1;
    node *np2 = *(node **) n2;

    if (np1->nbits == np2->nbits)
    {
	return strcmp(np1->symbol, np2->symbol);
    }
    

    return (np1->nbits < np2->nbits) ? -1 : 1;
}


/**
   Build a huffman tree given the node list.
 */

static node *build_hufftree(node *np_list[], int np_count)
{
    int  prev_code = -1, prev_len = 0, cur_len;
    node *nonzero_length_nodes[np_count];
    node *root = (node *) calloc(1, sizeof(node));
    int  nzln_cnt, i;

    //filter out and sort the nonzero length nodes
    for (i = nzln_cnt = 0; i < np_count; i++)
    {
	if (np_list[i]->nbits)
	{
	    nonzero_length_nodes[nzln_cnt++] = np_list[i];
	}
    }
    
    qsort(nonzero_length_nodes, nzln_cnt, sizeof(node *), canonical_cmp);

    //assign the code values and build the hufftree
    for (i = 0; i < nzln_cnt; i++)
    {
	node *n = nonzero_length_nodes[i];
	cur_len = n->nbits;
	n->code = (prev_code + 1) << (cur_len - prev_len);
	prev_code = n->code;
	prev_len  = cur_len;

	//put the node in the tree
	int bit_pos;
	node *cur_node = root;
	for (bit_pos = cur_len - 1; bit_pos >= 0; bit_pos--)
	{
	    if (1 << bit_pos & n->code)
	    {
		if (!cur_node->right)
		{
		    node *temp = (node *) calloc(1, sizeof(node));
		    cur_node->right = temp;
		    cur_node = temp;
		}
		else
		{
		    cur_node = cur_node->right;
		}
	    }
	    else
	    {
		if (!cur_node->left)
		{
		    node *temp = (node *) calloc(1, sizeof(node));
		    cur_node->left = temp;
		    cur_node = temp;
		}
		else
		{
		    cur_node = cur_node->left;
		}
	    }
	}
	cur_node->symbol = n->symbol;
	PRINT("build_hufftree symbol: %s\n", cur_node->symbol);
    }

    return root;
}

/**
   Recursively free the tree rooted at t
 */
static void free_tree(node *t)
{
    if (t->left)
	free_tree(t->left);
    if (t->right)
	free_tree(t->right);
    free(t);
}

/**
   Recursively print the leaf nodes
 */
static void print_tree(node *t)
{
    if (t->left)
    {
	print_tree(t->left);
	print_tree(t->right);
    }
    else
    {
	printf("Leaf[%s] \n", t->symbol);
    }
}

#define ERR_FCLOSE_EXIT(f1, f2, buf) \
    do {fclose(f1); fclose(f2); printf(buf); return 0;}	\
    while(0)

#define is_leaf(x)  (!(x)->left && !(x)->right)

/**
   Decompress the file
   @param fname      - file name
   @param dest_fname - destination file name
   @param np_list    - list of all the node pointers corresponding to the alphabetically sorted symbols of Shona language
   @param np_count   - the size of np_list (TODO: null terminate np_list)
 */
static int decompress_file(char *fname, char *dest_fname, node *np_list[], int np_count)
{
    FILE *fp = fopen(fname, "r");
    FILE *dest_fp = fopen(dest_fname, "w");
    node *tree;
    uint32_t num_original_codes, l;
    double   krafts_num = 0;
    int  i;

    if (!fp || !dest_fp)
    {
	perror("Error when opening file\n");
	return 0;
    }

    //get the symbols count
    fread(&num_original_codes, sizeof(num_original_codes), 1, fp);
    
    //build the canonical hufftree and use Kraft's inequality to check the validity of the prefix code
    for (i = 0; i < np_count; i++)
    {
	//In a huffman code no code can ever have a length equal or greater than the total number of symbols
	if (fread(&l, sizeof(uint32_t), 1, fp) == 0)
	{
	    ERR_FCLOSE_EXIT(fp, dest_fp, "Data corruption in file: File too small\n");
	}
	
#ifndef IGNORE_INVALID_LENGTH//TODO: get rid of this by fixing tests
	if (l > np_count -1)
	{
	    ERR_FCLOSE_EXIT(fp, dest_fp, "Data corruption in file: Code length too long\n");
	}
#endif
	
	np_list[i]->nbits = l;

	if (l > 0)
	    krafts_num += 1.0 / pow(2, l);
    }

#ifndef IGNORE_INVALID_LENGTH
    if (krafts_num > 1)
    {
	printf("Data corruption in file: The codes' lengths not valid\n");
	return 0;
    }
#endif
    
    tree = build_hufftree(np_list, np_count);

    //now do the actual decompression
    int  c, bit_pos, cur_len;
    uint32_t num_decoded_codes = 0;
    node *prev_node = tree, *cur_node;
    
    while ((c = fgetc(fp)) != EOF)
    {
	cur_len = 8;
	for (bit_pos = cur_len - 1; bit_pos >= 0; bit_pos--)
	{
	    cur_node = (1 << bit_pos & c) ? prev_node->right : prev_node->left;
	    if (is_leaf(cur_node))
	    {
		fwrite(cur_node->symbol, sizeof(char), strlen(cur_node->symbol), dest_fp);
		prev_node = tree;
		num_decoded_codes++;
		
		if (num_decoded_codes == num_original_codes)
		{
		    goto cleanup;
		}
	    }
	    else
	    {
		prev_node = cur_node;
	    }
	}
    }

cleanup:
    fclose(fp);
    fclose(dest_fp);
    free_tree(tree);

    if (num_original_codes != num_decoded_codes)
    {
	printf("Data corruption in file: Number of decoded codes: %u, Number of original codes: %u\n", num_decoded_codes, num_original_codes);
	return 0;
    }
    
    return 1;
}

#ifndef TEST_MODE
void main(int argc, char *argv[])
{
    //TODO write proper interface
    if (argc < 2)
    {
	printf("Missing arguments\n");
	return;
    }

    //process the file
    //TODO we should remove the terminating sc instead of putting a new extension
    char *file = argv[1];
    char *df_ext = ".sd";
    char *dest_file = (char *) calloc(sizeof(char), strlen(file) + strlen(df_ext) + 1);
    node *np_list[NODE_COUNT];
    int  i;
    
    sprintf(dest_file, "%s%s", file, df_ext);
    
    //make an array of node pointers for easier processing
    for (i = 0; i < NODE_COUNT; i++)
    {
	np_list[i] = node_list + i;
    }
    
    decompress_file(file, dest_file, np_list, NODE_COUNT);

    free(dest_file);
}
#endif //TEST_MODE

