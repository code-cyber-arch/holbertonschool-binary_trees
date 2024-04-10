#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (tree == NULL)
		return (NULL);
	if ((*tree) == NULL)
	{
		new = binary_tree_node(*tree, value);
		*tree = new;
		return (new);
	}
	if (value < (*tree)->n)
	{
		return (bst_insert(&(*tree)->left, value));
	}
	else if (value > (*tree)->n)
	{
		return (bst_insert(&(*tree)->right, value));
	}
	return (NULL);
}

