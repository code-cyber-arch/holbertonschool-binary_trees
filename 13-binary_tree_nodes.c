#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Description: Counts the number of nodes in a binary tree,
 * including the root node.
 * Return: nodes, 0 if the tree is empty.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);
	nodes += (tree->left || tree->right) ? 1 : 0;
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);
	return (nodes);
}
