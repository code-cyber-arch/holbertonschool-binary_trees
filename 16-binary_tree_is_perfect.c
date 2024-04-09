#include "binary_trees.h"

/**
 * power - Calculates the power of a number
 * @number: The base number
 * @to_power: The exponent
 *
 * Description: Calculates @number raised to the power of @to_power.
 * Return: the result of the calculation.
 */

static size_t power(size_t number, size_t to_power)
{
	size_t i, total = 1;

	for (i = 0; i < to_power; i++)
		total *= number;
	return (total);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Description: Checks if a binary tree is perfect, meaning all levels are
 * fully filled except possibly for the last level, which is filled from left
 * to right.
 * Return: 1 if perfect, 0 otherwise or if @tree is NULL.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, height, total = 0;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	height = binary_tree_height(tree);
	while (height > 0)
	{
		total += power(2, height);
		height--;
	}
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (size == (total + 1))
		return (1);
	else
		return (0);
}

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

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Description: This function calculates the height of a binary tree,
 * which is the maximum path length from the root to a leaf node.
 * Return: the height of the tree, or 0 if the tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight, rightHeight;

	if (tree == NULL)
		return (0);
	leftHeight = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rightHeight = tree->right ? 1 +  binary_tree_height(tree->right) : 0;

	return (leftHeight > rightHeight ? leftHeight : rightHeight);
}
