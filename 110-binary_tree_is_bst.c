#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node
 *
 * Return: 1 if BST, 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n < tree->n)
		return (0);

	if (tree->left && !binary_tree_is_bst(tree->left))
		return (0);

	if (tree->right && !binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}
