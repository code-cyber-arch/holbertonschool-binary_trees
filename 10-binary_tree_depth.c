#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure
 *
 * Description: Calculates the depth of a node in a binary tree, which
 * is the number of edges from the node to the tree's root.
 * Return: 0 if the node is NULL.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *current = tree;

	if (tree == NULL)
		return (0);
	while (current->parent != NULL)
	{
		depth++;
		current = current->parent;
	}
	return (depth);
}
