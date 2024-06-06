#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree
 *							using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t			*queue;
	binary_tree_t	*cursor;
	int		is_empty = 0;

	if (!tree || !func)
		return;

	cursor = (binary_tree_t *) tree;

	queue = create_queue();
	if (!queue)
		return;

	queue_push(queue, cursor);
	is_empty = queue_is_empty(queue);

	while (!is_empty)
	{
		cursor = queue_pop(queue);

		func(cursor->n);
		queue_push(queue, cursor->left);
		queue_push(queue, cursor->right);
	}
}

/**
 * create_queue - creates a queue
 * Return: pointer to the queue
 */
queue_t *create_queue(void)
{
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	if (!queue)
		return (0);

	queue->head = 0;
	queue->tail = 0;

	return (queue);
}

/**
 * queue_push - push a node to the queue
 * @queue: pointer to the queue
 * @node: pointer to the node
 */
void queue_push(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *new_node;

	if (!node)
		return;

	new_node = malloc(sizeof(queue_node_t));
	if (!new_node)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (!queue->head)
		queue->head = new_node;
	if (queue->tail)
		queue->tail->next = new_node;
	queue->tail = new_node;
}

/**
 * queue_pop - pop a node from the queue
 * @queue: pointer to the queue
 * Return: pointer to the node
 */
binary_tree_t *queue_pop(queue_t *queue)
{
	queue_node_t *node;
	binary_tree_t *tree_node;

	if (!queue->head)
		return (NULL);

	node = queue->head;
	tree_node = node->node;
	queue->head = node->next;
	free(node);

	return (tree_node);
}

/**
 * queue_is_empty - checks if a queue is empty
 * @queue: pointer to the queue
 * Return: 1 if empty, 0 otherwise
 */
int queue_is_empty(queue_t *queue)
{
	if (!queue->head)
		return (1);
	return (0);
}
