#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 *
 * Return: 1 if complete, 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (((tree->left && !tree->right) || (!tree->left && tree->right)))
		return (0);

	return (binary_tree_is_complete(tree->left) &&
			binary_tree_is_complete(tree->right));
}
