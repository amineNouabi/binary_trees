#include "binary_trees.h"

/**
 * binary_tree_height - computes tree height
 *
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t left_height = 0;
	size_t right_height = 0;

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	return (left_height < right_height ? right_height : left_height);
}
