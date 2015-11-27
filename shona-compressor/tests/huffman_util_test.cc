//tests for huffman_util.c

#include "../huffman_util.c"
#include "gtest/gtest.h"


void populate_heap(node **heap, node *n_list, int node_count)
{
    int i;
    for (i = 0; i < node_count; i++)
    {
	heap[i] = &n_list[i];
    }
}

/**
   build_min_heap tests
   - Single node
   - Two nodes
   - Similar nodes several
   - List that will form a balanced tree
   - List that will form an unbalances tree
   - Already heapified heap
   - A reverse heapified heap
 */


TEST(build_min_heapTest, single_node)
{
    const int node_count = 1;
    node n_list[node_count] = {
	{NULL, 0, 0, 3, NULL, NULL}
    };

    node *heap[node_count];
    
    populate_heap(heap, n_list, node_count);
    build_min_heap(heap, node_count);
    
    EXPECT_EQ(3, heap[0]->freq);
}

TEST(build_min_heapTest, two_nodes)
{
    const int node_count = 2;
    node n_list[node_count] = {
	{NULL, 0, 0, 3, NULL, NULL},
	{NULL, 0, 0, 2, NULL, NULL}
    };

    node *heap[node_count];

    populate_heap(heap, n_list, node_count);
    build_min_heap(heap, node_count);
    
    EXPECT_EQ(2, heap[0]->freq);
    EXPECT_EQ(3, heap[1]->freq);
}

TEST(build_min_heapTest, similar_nodes)
{
    const int node_count = 2;
    node n_list[node_count] = {
	{NULL, 0, 0, 3, NULL, NULL},
	{NULL, 0, 0, 3, NULL, NULL}
    };

    node *heap[node_count];

    populate_heap(heap, n_list, node_count);
    build_min_heap(heap, node_count);
    
    EXPECT_EQ(3, heap[0]->freq);
    EXPECT_EQ(3, heap[1]->freq);
    EXPECT_NE(heap[1], heap[2]);
}


TEST(build_min_heapTest, nodes_forming_balanced_heap)
{
    const int node_count = 7;
    node n_list[node_count] = {
	{NULL, 0, 0, 5, NULL, NULL},
	{NULL, 0, 0, 9, NULL, NULL},	
	{NULL, 0, 0, 8, NULL, NULL},
	{NULL, 0, 0, 4, NULL, NULL},
	{NULL, 0, 0, 3, NULL, NULL},
	{NULL, 0, 0, 7, NULL, NULL},
	{NULL, 0, 0, 6, NULL, NULL}
    };

    node *heap[node_count];
    
    populate_heap(heap, n_list, node_count);
    build_min_heap(heap, node_count);
    
    int i;
    int exp_freqs[node_count] = {3, 4, 6, 5, 9, 7, 8};
    for (i = 0; i < node_count; i++)
    {
	EXPECT_EQ(exp_freqs[i], heap[i]->freq);
    }
}

TEST(build_min_heapTest, nodes_forming_unbalanced_heap)
{
    const int node_count = 6;
    node n_list[node_count] = {
	{NULL, 0, 0, 9, NULL, NULL},
	{NULL, 0, 0, 5, NULL, NULL},	
	{NULL, 0, 0, 8, NULL, NULL},
	{NULL, 0, 0, 4, NULL, NULL},
	{NULL, 0, 0, 7, NULL, NULL},
	{NULL, 0, 0, 3, NULL, NULL}
    };
    
    node *heap[node_count];
    
    populate_heap(heap, n_list, node_count);
    build_min_heap(heap, node_count);
    
    int exp_freqs[node_count] = {3, 4, 8, 5, 7, 9};
    int i;
    for (i = 0; i < node_count; i++)
    {
	ASSERT_EQ(exp_freqs[i], heap[i]->freq);
    }
}

TEST(build_min_heapTest, already_balanced_heap)
{
    const int node_count = 6;
    node n_list[node_count] = {
	{NULL, 0, 0, 3, NULL, NULL},
	{NULL, 0, 0, 4, NULL, NULL},	
	{NULL, 0, 0, 8, NULL, NULL},
	{NULL, 0, 0, 5, NULL, NULL},
	{NULL, 0, 0, 7, NULL, NULL},
	{NULL, 0, 0, 9, NULL, NULL}
    };

    node *heap[node_count];
    
    populate_heap(heap, n_list, node_count);
    build_min_heap(heap, node_count);
    
    int exp_freqs[node_count] = {3, 4, 8, 5, 7, 9};
    int i;
    for (i = 0; i < node_count; i++)
    {
	EXPECT_EQ(exp_freqs[i], heap[i]->freq);
    }
}


/**
   hufftree_build tests
   - basic tree
 */

TEST(hufftree_buildTest, basic_tree)
{
    const int node_count = 7;
    node n_list[node_count] = {
	{NULL, 0, 0, 3, NULL, NULL},
	{NULL, 0, 0, 4, NULL, NULL},	
	{NULL, 0, 0, 8, NULL, NULL},
	{NULL, 0, 0, 5, NULL, NULL},
	{NULL, 0, 0, 7, NULL, NULL},
	{NULL, 0, 0, 9, NULL, NULL},
	{NULL, 0, 0, 10, NULL, NULL}
    };

    node *heap[node_count];
    populate_heap(heap, n_list, node_count);

    node *_malloced_nodes[node_count - 1];//because the nodes in n_list are not malloced unlike the actual code
    malloced_nodes = _malloced_nodes;
    mn_idx = 0;
    
    hufftree_build(heap, node_count);
    
    int top_idx = 0;
    node *agenda[node_count];//More size than is necessary (we only need about log(2, node_count))
    node *parent, *left, *right;
    
    agenda[0] = heap[0];

    while (top_idx >= 0)
    {
	parent = agenda[top_idx];
	left = parent->left;
	right = parent->right;

	if (left)
	{
	    agenda[top_idx++] = right;
	    agenda[top_idx] = left;
	    EXPECT_EQ(parent->freq, left->freq + right->freq);
        } else {
	    top_idx--;
	}
    }

    //free memory
    int i;
    for (i = 0; i < mn_idx; i++)
    {
	free(malloced_nodes[i]);
    }
}

/**
   hufftree_populate tests
   - basic tree
 */

TEST(hufftree_populateTest, basic_tree)
{
    const int node_count = 5;
    node n_list[node_count] = {
	{NULL, 0, 0, 0, NULL, NULL},
	{NULL, 0, 0, 0, NULL, NULL},	
	{NULL, 0, 0, 0, NULL, NULL},
	{NULL, 0, 0, 0, NULL, NULL},
	{NULL, 0, 0, 0, NULL, NULL},
    };

    int tree_map[node_count][2] = {
	{1, 2},//<-0
	{0},   //  1 Leaf
	{3, 4},//<-2
	{0},   //  3 Leaf
	{0}    //  4 Leaf
    };
    
#define get_node_ptr(i, j) &(n_list[tree_map[i][j]])
#define get_left(i)        get_node_ptr(i, 0)
#define get_right(i)       get_node_ptr(i, 1)

    node *root = &n_list[0];
    
    int i;
    for (i = 0; i < node_count; i++)
    {
	if (!tree_map[i][0])
	    continue;
	
	n_list[i].left = get_left(i);
	n_list[i].right = get_right(i);
    }

    hufftree_populate(root);

    EXPECT_EQ(0, n_list[1].code);
    EXPECT_EQ(1, n_list[1].nbits);

    EXPECT_EQ(2, n_list[3].code);
    EXPECT_EQ(2, n_list[3].nbits);

    EXPECT_EQ(3, n_list[4].code);
    EXPECT_EQ(2, n_list[4].nbits);
}

/**
   canonize_codebook tests
   - all nodes have the same length
   - various lengths
 */


TEST(canonize_codebook, same_length)
{
    const int node_count = 4;
    node n_list[node_count] = {
	{(char *) "B", 0, 2, 0, NULL, NULL},
	{(char *) "C", 0, 2, 0, NULL, NULL},
	{(char *) "A", 0, 2, 0, NULL, NULL},
	{(char *) "D", 0, 2, 0, NULL, NULL}
    };

    node *codebook[node_count];
    node *codebook_cpy[node_count];
    
    populate_heap(codebook, n_list, node_count);
    populate_heap(codebook_cpy, n_list, node_count);
    
    canonize_codebook(codebook, node_count);

    int exp_codes[node_count] = {0, 1, 2, 3};

    int i;
    for (i = 0; i < node_count; i++)
    {
	EXPECT_EQ(exp_codes[i], codebook[i]->code);
    }
}

TEST(canonize_codebook, different_length)
{
    const int node_count = 4;
    node n_list[node_count] = {
	{(char *) "B", 0, 1, 0, NULL, NULL},
	{(char *) "C", 0, 3, 0, NULL, NULL},
	{(char *) "A", 0, 3, 0, NULL, NULL},
	{(char *) "D", 0, 2, 0, NULL, NULL}
    };

    node *codebook[node_count];
    node *codebook_cpy[node_count];
    
    populate_heap(codebook, n_list, node_count);
    populate_heap(codebook_cpy, n_list, node_count);
    
    canonize_codebook(codebook, node_count);

    int exp_codes[node_count] = {0, 2, 6, 7};

    int i;
    for (i = 0; i < node_count; i++)
    {
	EXPECT_EQ(exp_codes[i], codebook[i]->code);
    }
}


/**
   get_codebook tests
   - basic tree
 */


TEST(get_codebook, basic_tests)
{
    const int node_count = 4;
    node _n_list[node_count] = {
	{(char *) "A", 0, 0, 5, NULL, NULL},
	{(char *) "B", 0, 0, 5, NULL, NULL},
	{(char *) "C", 0, 0, 10, NULL, NULL},
	{(char *) "D", 0, 0, 10, NULL, NULL}
    };

    node *n_list[node_count];
    
    populate_heap(n_list, _n_list, node_count);
    
    get_codebook(n_list, node_count);

    int freq_length = 0;
    int i;

    for (i = 0; i < node_count; i++)
    {
	node *n = n_list[i];
	freq_length += (n->freq * n->nbits);
    }

    int average_length = freq_length / 30;

    EXPECT_EQ(2, average_length);
}
