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
	size_t leaves;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right != NULL)
		leaves = 2;
	else
		leaves = 1;
	return (leaves);
}
