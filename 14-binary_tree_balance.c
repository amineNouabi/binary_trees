#include "binary_trees.h"

/**
 * binary_tree_balance - computes balance factor of a node
 * @tree: pointer to the root node
 *
 * Return: balance factor of the node
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	return (left_height - right_height);
}


/**
 * binary_tree_height - computes tree height
 * @tree: pointer to the root node
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);


	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);

	return (right_height);
}
