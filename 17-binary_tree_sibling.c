#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a binary tree node
 * @node: Pointer to the node to find the sibling of
 *
 * Description: Finds the sibling of a given node in a binary tree.
 * Return: NULL if the node is NULL, has no parent, or its parent has
 * no siblings. Otherwise, returns a pointer to the sibling node.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
			node->parent->left == NULL || node->parent->right == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
