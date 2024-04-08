#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Description: Counts the number of leaf nodes (nodes with no children)
 * in a binary tree.
 * Return: Leaves, 0 if the tree is empty.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);
	leaves += (!tree->left && !tree->right) ? 1 : 0;
	leaves += (binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left));
	return (leaves);
}
