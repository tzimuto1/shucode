#include "huffman_util.h"
#include "data.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 1

node **malloced_nodes;
int  mn_idx;

//##############################################################################
//HEAP FUNCTIONS

static void min_heapify(node **heap, int heap_size, int parent_pos)
{
    int  left_pos = 2 * parent_pos + 1;
    int  right_pos = 2 * parent_pos + 2;
    int  smallest_pos = parent_pos;
    node *parent = heap[parent_pos];
    node *smallest = parent;

#ifdef DEBUG
    printf("Func: %s, heap_size: %i, parent_pos: %i\n", __func__, heap_size, parent_pos);
#endif
    
    if (left_pos < heap_size && heap[left_pos]->freq < parent->freq)
    {
        smallest_pos = left_pos;
	smallest = heap[smallest_pos];
    }
    
    if (right_pos < heap_size && heap[right_pos]->freq < smallest->freq)
    {
        smallest_pos = right_pos;
	smallest = heap[smallest_pos];
    }
    
    if (smallest_pos != parent_pos)
    {
	heap[smallest_pos] = parent;
	heap[parent_pos]   = smallest;
	min_heapify(heap, heap_size, smallest_pos);
    }
}

static void build_min_heap(node **heap, int heap_size)
{
    int i;

    if (!heap)
	return;

    for (i = heap_size / 2 - 1; i >= 0; i--)
    {
	min_heapify(heap, heap_size, i);
    }
}

//##############################################################################
//HUFFMAN TREE FUNCTIONS

/*
 * Populates the hufftree with code and code lengths
 */
static void hufftree_populate(node *parent)
{
    node *left = parent->left;
    node *right = parent->right;
    if (left)
    {
	left->code = (parent->code)<< 1;
	left->nbits = (parent->nbits) + 1;
	hufftree_populate(left);

	right->code = ((parent->code)<< 1) + 1;//Ugh!
	right->nbits = (parent->nbits) + 1;
	hufftree_populate(right);
    }    
}

/*
 * Builds a basic tree from the heap. No population occurs
 */
static void hufftree_build(node **heap, int heap_size)
{
    if (heap_size == 1)
    {
	return;
    }
    
    node new_node, *left, *right, *_new;

    //extract the two minimum freq nodes
    left = heap[0];
    heap[0] = heap[heap_size -1];
    heap_size--;
    
    min_heapify(heap, heap_size, 0);

    right = heap[0];

    new_node = (node) {
	NULL, 0, 0, (left->freq + right->freq), left, right
    };
    _new = (node *) malloc(sizeof(node));
    *_new = new_node; 
    heap[0] = _new;
    malloced_nodes[mn_idx++] = _new;

    min_heapify(heap, heap_size, 0);

    hufftree_build(heap, heap_size);
}


//##############################################################################
//Functions to process our code book

/**
   Compare nodes for ordering first by code length and then by symbol
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
 * Make the huffman code into a canonical form
 */
static void canonize_codebook(node **codebook, const int count)
{
    
    qsort(codebook, count, sizeof(node *), canonical_cmp);

    int prev_code = -1, prev_len = 0, cur_len, i;

    for (i = 0; i < count; i++)
    {
	cur_len = codebook[i]->nbits;
	codebook[i]->code = (prev_code + 1) << (cur_len - prev_len);
	
#if DEBUG
	printf("Func: %s, Symbol: %s, prev_len: %i, cur_len: %i, prev_code: %i, cur_code: %i\n", __func__, codebook[i]->symbol, prev_len, cur_len, prev_code, codebook[i]->code);
#endif
	
	prev_code = codebook[i]->code;
	prev_len = cur_len;
    }
}

//##############################################################################
//Functions exposed to external functions

/**
   Populates n_list with the codes and code lengths based on the frequency.
 */

void get_codebook(node **n_list, const int node_count)
{
    //some defensive programming
    if (!n_list || node_count <= 0)
	return;
    
    int  malloced_node_cnt = 2 * node_count - 1;
    node *heap[node_count];
    node *raw_codebook[node_count];
    node *hufftree_root;

    malloced_nodes = (node **) malloc(sizeof(node *) * malloced_node_cnt);
    mn_idx = 0;
    
    //build min heap
    /*
    At this stage both heap and raw_codebook contain the pointers to the nodes in
    n_list in the right order. Order in heap will change as we build min heap and
    make the hufftree. Order in raw_codebook will change as we canonize the codebook.
    We do this so that we do not tamper with the ordering in n_list
    */
    memcpy(heap, n_list, sizeof(node *) * node_count);
    memcpy(raw_codebook, n_list, sizeof(node *) * node_count);
    build_min_heap(heap, node_count);
    //build hufftree and populate it
    hufftree_build(heap, node_count);
    hufftree_root = heap[0];
    hufftree_populate(hufftree_root);
    canonize_codebook(raw_codebook, node_count);
    
    //free memory
    int i;
    for (i = 0; i < mn_idx; i++)
    {
	free(malloced_nodes[i]);
    }
    free(malloced_nodes);
}
