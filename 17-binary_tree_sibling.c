#include "binary_trees.h"


/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node
 *
 * Return: The sibling of the node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (0);

	parent = node->parent;

	if (parent->left == node)
		return (parent->right);

	return (parent->left);
}
