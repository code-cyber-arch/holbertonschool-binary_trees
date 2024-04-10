#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The value of the smallest node visited thus far.
 * @max: The value of the largest node visited this far.
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		return (check_bst(tree->left, min, tree->n - 1) &&
				check_bst(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_bst(tree, INT_MIN, INT_MAX));
}

