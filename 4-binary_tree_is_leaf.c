#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: node to check
 *
 * Return: void
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (1);

	return (0);
}
