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

	if (!is_lower(tree->left, tree->n) || !is_greater(tree->right, tree->n))
		return (0);

	if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}

/**
 * is_lower - checks if all nodes are lower than n
 * @tree: pointer to the root node
 * @n: value to compare
 *
 * Return: 1 if all nodes are lower, 0 if not
 */
int is_lower(const binary_tree_t *tree, int n)
{
	if (!tree)
		return (1);

	if (tree->n >= n)
		return (0);

	return (is_lower(tree->left, n) && is_lower(tree->right, n));
}


/**
 * is_greater - checks if all nodes are greater than n
 * @tree: pointer to the root node
 * @n: value to compare
 *
 * Return: 1 if all nodes are greater, 0 if not
 */
int is_greater(const binary_tree_t *tree, int n)
{
	if (!tree)
		return (1);

	if (tree->n <= n)
		return (0);

	return (is_greater(tree->left, n) && is_greater(tree->right, n));
}
