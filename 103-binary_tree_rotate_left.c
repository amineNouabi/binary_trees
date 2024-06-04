#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node
 *
 * Return: pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;
	binary_tree_t *temp;

	if (!tree)
		return (0);

	new_root = tree->right;
	if (!new_root)
		return (0);

	new_root->parent = 0;

	temp = new_root->left;
	new_root->left = tree;

	if (temp)
		temp->parent = tree;
	tree->parent = new_root;
	tree->right = temp;

	return (new_root);
}
