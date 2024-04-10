#include "binary_trees.h"

/**
 * FindMin - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 */
bst_t *FindMin(bst_t *root)
{
	if (root == NULL)
	{
		return (NULL);
	}
	else if (root->left == NULL)
	{
		return (root);
	}
	else
	{
		return (FindMin(root->left));
	}
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
	bst_t *temp;

	if (root == NULL)
		return (root);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL)
		{
			temp = root;
			root = root->left;
			free(temp);
		}
		else
		{
			temp = FindMin(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}

