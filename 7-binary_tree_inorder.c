#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs In-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 *
 * Description: Traverses the tree in in-order, calling @func on
 * each node's value.
 * Does nothing if @tree or @func is NULL.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
