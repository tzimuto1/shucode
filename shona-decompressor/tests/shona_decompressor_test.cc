#define TEST_MODE
#include "../shona_decompressor.c"
#include "gtest/gtest.h"

/**
   build_hufftree tests
   - basic np_list with nodes of zero and nonzero length
 **/

#define STR(x) (char *) x

#define CODE   0
#define FREQ   0
#define SIZE   0
#define CHILD  NULL


TEST(build_hufftreeTest, basic)
{
    //populate the input structure and call func
    const int cb_len = 8;
    node n_list[cb_len] = {
	{STR("Sho"), CODE, 3, FREQ, CHILD, CHILD},
	{STR("Zi"),  CODE, 3, FREQ, CHILD, CHILD},
	{STR("Ha"),  CODE, 0, FREQ, CHILD, CHILD},
	{STR("a"),   CODE, 3, FREQ, CHILD, CHILD},
	{STR("bwe"), CODE, 4, FREQ, CHILD, CHILD},
	{STR("mba"), CODE, 1, FREQ, CHILD, CHILD},
	{STR("d"),   CODE, 0, FREQ, CHILD, CHILD},
	{STR("na"),  CODE, 4, FREQ, CHILD, CHILD}
    };
    
    node *np_list[cb_len];
    int i;
    for (i = 0; i < cb_len; i++)
    {
	np_list[i] = n_list + i;
    }

    node *root = build_hufftree(np_list, cb_len);

    //expected and actual data
    const int exp_sym_len = 6;
    const char *exp_symbols[exp_sym_len] = {
	STR("mba"), STR("Sho"),
	STR("Zi"), STR("a"),
	STR("bwe"), STR("na")
    };


    const char *act_symbols[exp_sym_len];
    
    //go through the tree and populate act_symbols
    int top_idx = 0;
    node *agenda[12];//by inspection, too tired TODO the math
    node *parent, *left, *right;

    i = 0;
    agenda[0] = root;

    while (top_idx >= 0)
    {
	parent = agenda[top_idx];
	left = parent->left;
	right = parent->right;

	if (left)
	{
	    agenda[top_idx++] = right;
	    agenda[top_idx] = left;
	} else {
	    act_symbols[i++] = parent->symbol;
	    top_idx--;//pop!
	}
    }

    ASSERT_EQ(exp_sym_len, i);
    //now do the actual testing
    for (i = 0; i < exp_sym_len; i++)
    {
	EXPECT_STREQ(exp_symbols[i], act_symbols[i]);
    }

    //clean up
    free_tree(root);
    
}


//TODO do proper cleanup regardless of what happens
TEST(decompress_fileTest, basic_file)
{
 
    const uint32_t cb_len  = 8;
    const int      num_codes = 6;
    const int      vnc = 3;
    int i;
    
    //populate the input structure   
    node n_list[cb_len] = {
	{STR(" "),   CODE, SIZE, FREQ, CHILD, CHILD},
	{STR("Ndi"), CODE, SIZE, FREQ, CHILD, CHILD},
	{STR("Zi"),  CODE, SIZE, FREQ, CHILD, CHILD},
	{STR("mu"),  CODE, SIZE, FREQ, CHILD, CHILD},
	{STR("ri"),  CODE, SIZE, FREQ, CHILD, CHILD},
	{STR("mbo"), CODE, SIZE, FREQ, CHILD, CHILD},
	{STR("z"),   CODE, SIZE, FREQ, CHILD, CHILD},
	{STR("za"),  CODE, SIZE, FREQ, CHILD, CHILD}
    };
   
    node *np_list[cb_len];
    
    for (i = 0; i < cb_len; i++)
    {
	np_list[i] = n_list + i;
    }

    uint32_t      codebook[cb_len] = {4, 2, 2, 4, 2, 3, 0, 0};
    unsigned char codes[vnc] = {46, 247, 0};
    
    //the files
    char *fname = "./shona_decompressor_test_files/empty.txt.sc";
    char *dest_fname = "./shona_decompressor_test_files/empty";

    FILE *fp = fopen(fname, "w");
    ASSERT_TRUE(fp != NULL);
    
    //write the number of codes
    fwrite(&num_codes, sizeof(uint32_t), 1, fp);

    //write the codebook
    fwrite(codebook, sizeof(uint32_t), cb_len, fp);
    
    //write the codes and padding
    fwrite(codes, sizeof(char), vnc, fp);
    
    fclose(fp);

    //now the function call
    int status = decompress_file(fname, dest_fname, np_list, cb_len);
    EXPECT_TRUE(status);

    //now the testing
    char *exp_data = "Ndiri muZimbo";
    FILE *dest_fp = fopen(dest_fname, "r");
    ASSERT_TRUE(dest_fp != NULL);

    char   *line = NULL;
    size_t size = 0;

    EXPECT_GT(getline(&line, &size, dest_fp), 0);
    EXPECT_STREQ(exp_data, line);    
    EXPECT_EQ(-1, getline(&line, &size, dest_fp));

    //final clean up
    fclose(dest_fp);
    unlink(dest_fname);
    unlink(fname);    
}

