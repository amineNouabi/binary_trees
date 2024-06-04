

#include "binary_trees.h"


/**
 * binary_trees_ancestor - finds nearest ancestor of two nodes
 * @first: first node
 * @second: second node
 *
 * Return: The uncle of the node.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	binary_tree_t *cursor;

	if (!first || !second)
		return (0);

	cursor = (binary_tree_t *) first;
	while (cursor)
	{
		if (binary_trees_find_node(cursor, second))
			return (cursor);

		cursor = cursor->parent;
	}

	return (0);
}

/**
 * binary_trees_find_node - Search for node existance in binary tree
 * @root: pointer to the node
 * @node: node that we search
 *
 * Return: Sum of occurences of the address of the node in the tree
 */
int binary_trees_find_node(const binary_tree_t *root,
							const binary_tree_t *node)
{
	if (!root)
		return (0);

	if (root == node)
		return (1);

	return (binary_trees_find_node(root->left, node) +
			binary_trees_find_node(root->right, node));
}
