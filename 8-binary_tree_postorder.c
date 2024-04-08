#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs Post-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 *
 * Description: Traverses the tree in post-order, calling @func on
 * each node's value.
 * Does nothing if @tree or @func is NULL.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
