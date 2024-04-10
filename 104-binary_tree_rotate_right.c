#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_root = tree->left;
	tmp = new_root->right;

	new_root->right = tree;
	new_root->parent = NULL;
	tree->parent = new_root;

	if (tmp != NULL)
		tmp->parent = tree;
	tree->left = tmp;
	return (new_root);
}

