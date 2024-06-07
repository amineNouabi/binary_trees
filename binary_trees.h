#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct queue_node_s - queue linked list
 *
 * @node: pointer to binary tree node
 * @next: pointer to next node
 */
struct queue_node_s
{
	struct binary_tree_s *node;
	struct queue_node_s *next;
};

/**
 * struct queue_s - queue linked list
 *
 * @head: pointer to head of the queue
 * @tail: pointer to tail of the queue
 */
struct queue_s
{
	struct queue_node_s *head;
	struct queue_node_s *tail;
};

typedef struct queue_node_s queue_node_t;
typedef struct queue_s queue_t;


void binary_tree_print(const binary_tree_t *);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);

size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);

int binary_tree_balance(const binary_tree_t *tree);

int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second);
int binary_trees_find_node(const binary_tree_t *root,
				const binary_tree_t *node);

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);

int binary_tree_is_bst(const binary_tree_t *tree);

/* Queue functions */
queue_t *create_queue(void);
void queue_push(queue_t *queue, binary_tree_t *node);
binary_tree_t *queue_pop(queue_t *queue);

#endif /* _BINARY_TREES_H_ */
