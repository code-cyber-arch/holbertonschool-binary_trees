#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * Description: Checks if every node in a binary tree has
 * either 0 or 2 children, making it a full binary tree.
 * Return: 1 if full, 0 otherwise or if @tree is NULL.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left == NULL && tree->right == NULL) ||
	    (tree->left != NULL && tree->right != NULL &&
	     binary_tree_is_full(tree->left) &&
	     binary_tree_is_full(tree->right)))
		return (1);

	return (0);
}
