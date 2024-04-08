#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Description: Calculates the total number of nodes in the binary tree.
 * Return: size, 0 if the tree is empty.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);
	size = size + binary_tree_size(tree->left);
	size = size + binary_tree_size(tree->right);
	return (size);
}
