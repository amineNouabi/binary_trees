#include "binary_trees.h"

/**
 * binary_tree_size - computes node size
 * @tree: pointer to the root node
 *
 * Return: size of the node
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	size += 1;

	if (tree->left)
		size += binary_tree_size(tree->left);

	if (tree->right)
		size += binary_tree_size(tree->right);

	return (size);
}
