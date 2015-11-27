//tests for compression_util.c

#include "../compression_util.c"
#include "gtest/gtest.h"


/**
   empty file
   file that doesn't need padding
   file that needspadding
*/
#define SYMBOL NULL
#define FREQ   0
#define CHILD  NULL

const int cb_len = 7;
node codebook[cb_len] = {
    {SYMBOL, 0, 1, FREQ, CHILD, CHILD},
    {SYMBOL, 4, 3, FREQ, CHILD, CHILD},
    {SYMBOL, 6, 3, FREQ, CHILD, CHILD},
    {SYMBOL, 7, 3, FREQ, CHILD, CHILD},
    {SYMBOL, 10, 4, FREQ, CHILD, CHILD},
    {SYMBOL, 11, 4, FREQ, CHILD, CHILD},
    {SYMBOL, 0X80102, 20, FREQ, CHILD, CHILD}
};

//TODO unlink the file and close it no matter what happens (well except when apocalypse happens)

TEST(compress_fileTest, empty_file)
{
    const int num_elem = 0;
    node *list[num_elem];
    file_data fd = {
	list,
	num_elem,
	num_elem
    };
    
    char *dest_file = "./compression_util_test_files/empty_file.txt";

    int status = compress_file(&fd, codebook, cb_len, dest_file);

    //check if file compression failed
    ASSERT_NE(0, status);

    FILE *fp = fopen(dest_file, "r");
    
    //check if file opening failed
    ASSERT_TRUE(fp != NULL);

    //length check
    uint32_t actual_len;
    fread(&actual_len, sizeof(actual_len), 1, fp);
    ASSERT_EQ(num_elem, actual_len);

    //codebook check
    uint32_t l, i = 0;
    while (fread(&l, sizeof(uint32_t), 1, fp) > 0)
    {
	ASSERT_GT(cb_len, i);
	EXPECT_EQ(codebook[i++].nbits, l);
    }

    EXPECT_GT(0, fgetc(fp));
    
    fclose(fp);
    unlink(dest_file);
}

TEST(compress_fileTest, without_padding)
{
    const int num_elem = 10;
    node *list[num_elem] = {
	codebook + 0,
	codebook + 1,
	codebook + 5,
	codebook + 4,
	codebook + 2,
	codebook + 3,
	codebook + 0,
	codebook + 0,
	codebook + 0,
	codebook + 2
    };
    
    file_data fd = {
	list,
	num_elem,
	num_elem
    };
    
    char *dest_file = "./compression_util_test_files/without_padding_file.txt";

    int status = compress_file(&fd, codebook, cb_len, dest_file);

    //check if file compression failed
    ASSERT_NE(0, status);

    FILE *fp = fopen(dest_file, "r");
    
    //check if file opening failed
    ASSERT_TRUE(fp != NULL);

    //length check
    uint32_t actual_len;
    fread(&actual_len, sizeof(actual_len), 1, fp);
    ASSERT_EQ(num_elem, actual_len);

    //codebook check
    uint32_t l, i = 0;
    while (i < cb_len  )
    {
	fread(&l, sizeof(uint32_t), 1, fp);
	EXPECT_EQ(codebook[i++].nbits, l);
    }

    //data check
    const int num_data_bytes = 3;
    uint32_t exp_data[num_data_bytes] = {75, 173, 198};
    int c;
    i = 0;
    
    while (i < num_data_bytes)
    {
	c = fgetc(fp);
	EXPECT_EQ(exp_data[i++], c);
    }

    ASSERT_GT(0, fgetc(fp));
   
    fclose(fp);
    unlink(dest_file);
}

/**
   This test also covers the case where we have a symbol corresponding to a code a length > one byte. This would cause the compression utility to chunk the code into several bytes before it reads the next symbol
 */
TEST(compress_fileTest, with_padding)
{
    const int num_elem = 6;
    node *list[num_elem] = {
	codebook + 5,
	codebook + 1,
	codebook + 4,
	codebook + 6,
	codebook + 0,
	codebook + 3
    };
    
    file_data fd = {
	list,
	num_elem,
	num_elem
    };
    
    char *dest_file = "./compression_util_test_files/with_padding_file.txt";

    int status = compress_file(&fd, codebook, cb_len, dest_file);

    //check if file compression failed
    ASSERT_NE(0, status);

    FILE *fp = fopen(dest_file, "r");
    
    //check if file opening failed
    ASSERT_TRUE(fp != NULL);

    //length check
    uint32_t actual_len;
    fread(&actual_len, sizeof(actual_len), 1, fp);
    ASSERT_EQ(num_elem, actual_len);

    //codebook check
    uint32_t l, i = 0;
    while (i < cb_len  )
    {
	fread(&l, sizeof(uint32_t), 1, fp);
	EXPECT_EQ(codebook[i++].nbits, l);
    }
    
    //data check
    const int num_data_bytes = 5;
    uint32_t exp_data[num_data_bytes] = {185, 80, 2, 4, 224};
    int c;
    i = 0;
    
    while (i < num_data_bytes)
    {
	c = fgetc(fp);
	EXPECT_EQ(exp_data[i++], c);
    }

    ASSERT_GT(0, fgetc(fp));
   
    fclose(fp);
    unlink(dest_file);
}


