#include "binary_trees.h"
/**
 * get_avl_balance - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */
void get_avl_balance(avl_t **tree)
{
	int value;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	get_avl_balance(&(*tree)->left);
	get_avl_balance(&(*tree)->right);
	value = binary_tree_balance((const binary_tree_t *)*tree);
	if (value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * get_successor - get the next successor of the min node in the subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int get_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = get_successor(node->left);
		if (left == 0)
			return (node->n);
		return (left);
	}
}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = get_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * avl_remove_recursion - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *avl_remove_recursion(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		avl_remove_recursion(root->left, value);
	else if (value > root->n)
		avl_remove_recursion(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			avl_remove_recursion(root->right, type);
	}
	else
		return (NULL);
	return (root);
}
/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) avl_remove_recursion((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	get_avl_balance(&root_a);
	return (root_a);
}

