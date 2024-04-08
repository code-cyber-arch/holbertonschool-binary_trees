#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root node
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a root (with children), 0 otherwise or if NULL.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL || node->right == NULL)
		return (0);
	return (1);
}
