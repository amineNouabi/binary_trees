#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes a binary tree
 * @tree: pointer to the root node
 *
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	if (tree->left)
		binary_tree_delete(tree->left);

	if (tree->right)
		binary_tree_delete(tree->right);

	free(tree);
}
