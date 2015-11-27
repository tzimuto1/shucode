//Listing of tests
#define TEST_MODE
#include "../shona_compressor.c"
#include "gtest/gtest.h"

/**
   1. \t, N, ~
 */

TEST(get_alphabet_posTest, all)
{
    char c            = '\t';
    int  pos_expected = 0;
    int  pos          = get_alphabet_pos(c);
    EXPECT_EQ(pos_expected, pos);

    c            = 'B';
    pos_expected = 37;
    pos          = get_alphabet_pos(c);
    EXPECT_EQ(pos_expected, pos);

    c            = '~';
    pos_expected = 97;
    pos          = get_alphabet_pos(c);
    EXPECT_EQ(pos_expected, pos);
}

/**
   - Any of the control characters: \t \n \r \s
   - Any char before the alpha char: 0
   - Single alpha char: C
   - Shona Syllable: Chwa, n'a, 
   - Back slash:
   - Last Characer: ~
   - Non existing node
 */

TEST(get_nodeTest, control_chars)
{
    //control chars
    char *symbol = "\t";
    node *node_p = get_node(symbol);
    ASSERT_TRUE(node_p != NULL);
    EXPECT_STREQ(symbol, node_p->symbol);
    
    symbol = " ";
    ASSERT_TRUE(node_p != NULL);
    node_p  = get_node(symbol);
    EXPECT_STREQ(symbol, node_p->symbol);
}

TEST(get_nodeTest, char_before_alpha)
{
    //any char before the alpha chars
    char *symbol = "0";
    node *node_p = get_node(symbol);
    ASSERT_TRUE(node_p != NULL);
    EXPECT_STREQ(symbol, node_p->symbol);
}

TEST(get_nodeTest, alphas)
{
    //Single alpha char
    char *symbol = "C";
    node *node_p = get_node(symbol);
    ASSERT_TRUE(node_p != NULL);
    EXPECT_STREQ(symbol, node_p->symbol);

    //Shona syllables
    symbol = "Nzwa";
    node_p = get_node(symbol);
    ASSERT_TRUE(node_p != NULL);
    EXPECT_STREQ(symbol, node_p->symbol);

    symbol = "n'a";
    node_p = get_node(symbol);
    ASSERT_TRUE(node_p != NULL);
    EXPECT_STREQ(symbol, node_p->symbol);
}

TEST(get_nodeTest, back_slash)
{
    //Back Slash
    char *symbol = "\\";
    node *node_p = get_node(symbol);
    ASSERT_TRUE(node_p != NULL);
    EXPECT_STREQ(symbol, node_p->symbol);
}

TEST(get_nodeTest, last_node)
{
    //Last Node
    char *symbol = "~";
    node *node_p = get_node(symbol);
    ASSERT_TRUE(node_p != NULL);
    EXPECT_STREQ(symbol, node_p->symbol);
}

TEST(get_nodeTest, no_match)
{
    //No matching node
    char *symbol = "HelloWorld";
    node *node_p = get_node(symbol);
    ASSERT_EQ(NULL, node_p);
}

/**
 * process_input tests
 
 - empty file
 - file with single repeated character
 - file with pure Shona (not really) 
 */

TEST(process_inputTest, empty_file)
{
    char      *file = "./files/empty.txt";
    file_data *fd   = process_input(file);

    //check validity of file data
    EXPECT_EQ(0, fd->num_elem);
}

TEST(process_inputTest, repeated_char_file)
{
    char      *file = "./files/repeated_char.txt";
    file_data *fd   = process_input(file);
    int       i;
    
    //check validity of file data
    ASSERT_EQ(9, fd->num_elem);
    for (i = 0; i < fd->num_elem - 1; i++)
    {
	EXPECT_STREQ("A", fd->list[0]->symbol);

	if (i > 0)
	    EXPECT_EQ(fd->list[i - 1], fd->list[i]);
    }

    EXPECT_STREQ("\n", fd->list[8]->symbol);
    
    //check validity of node list
    EXPECT_EQ(8, fd->list[0]->freq);
    EXPECT_EQ(1, fd->list[8]->freq);
}

TEST(process_inputTest, pure_shona_file)
{
    char      *file = "./files/pure_shona.txt";
    file_data *fd   = process_input(file);
    
    //check validity of file data
    ASSERT_EQ(24, fd->num_elem);
    EXPECT_STREQ("Nyi", fd->list[0]->symbol);
    EXPECT_STREQ(" ", fd->list[2]->symbol);
    EXPECT_STREQ("1", fd->list[18]->symbol);

    //check validity of node list
    EXPECT_EQ(2, fd->list[1]->freq);
    EXPECT_EQ(4, fd->list[2]->freq);
}
