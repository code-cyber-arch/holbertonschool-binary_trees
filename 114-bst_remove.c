#include "binary_trees.h"

bst_t *get_minimum(bst_t *root);
bst_t *bst_do_delete(bst_t *root, bst_t *node);
bst_t *bst_find_node_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * get_minimum - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *get_minimum(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_do_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_do_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *minimum = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	minimum = get_minimum(node->right);
	node->n = minimum->n;
	return (bst_do_delete(root, minimum));
}
/**
 * bst_find_node_recursive - find the node and go to delete.
 * @root: A pointer to the root node;
 * @node: A pointer to the current node
 * @value: The value to remove from the BST.
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_find_node_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n < value)
		{
			return (bst_find_node_recursive(root, node->right, value));
		}
		else if (node->n > value)
		{
			return (bst_find_node_recursive(root, node->left, value));
		}
		else
		{
			return (bst_do_delete(root, node));
		}
	}
	return (NULL);
}
/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 * Return: A pointer to the new root node after deletion.
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_find_node_recursive(root, root, value));
}

