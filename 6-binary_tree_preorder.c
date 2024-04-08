#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs pre-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 *
 * Description: Traverses the tree in pre-order, calling @func on
 * each node's value.
 * Does nothing if @tree or @func is NULL.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
