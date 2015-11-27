#ifndef DATA_H
#define DATA_H
#include <stdint.h>

/*********************************************************************
     Below is a description of the limitations of the program
     - code length = 32 bits
     - code <= 2^32 -1
     - nbits <= 32
     - file_data.num_elem <= 2^32 -1
     -> the maximum file size is 2^32 -1 bytes
*********************************************************************/


/**
 * This is the fundamental data type in our code. It is used by input processor (in shona_compressor) to record the symbol frequences. A list of these nodes will record the file data in order. The huffman encoding utility will use this to build a min heap and a huffman tree.
 */
typedef struct node {
    const char *symbol;
    uint32_t   code;
    int        nbits;
    int        freq;
    struct node *left;
    struct node *right;
    int         in_file;
} node;

/**
 * Stores data from the input file in the form of nodes matching each of the symbols in the file. We have a memory penalty by doing this, but we don't want to read the file again
 */
typedef struct file_data {
    node      **list;
    uint32_t  num_elem;
    uint32_t  num_alloced;
} file_data;

extern const char shona_regex[];
extern node  node_list[];
extern const int  NODE_COUNT;
extern const int  printable_char_ranges[][2];


#endif
