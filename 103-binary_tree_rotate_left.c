#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	new_root = tree->right;
	tmp = new_root->left;

	new_root->left = tree;
	new_root->parent = NULL;
	tree->parent = new_root;

	if (tmp != NULL)
		tmp->parent = tree;
	tree->right = tmp;
	return (new_root);
}

