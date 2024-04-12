#include "binary_trees.h"


/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
int height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + height(tree->left) : 1;
	right_height = tree->right ? 1 + height(tree->right) : 1;
	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * get_balance - get_balance
 * @tree: root node
 * Return: If tree is NULL, return 0, else return balance.
 */
int get_balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **root, avl_t *parent, avl_t **new, int value)
{
	int balance;

	if (*root == NULL)
		return (*new = binary_tree_node(parent, value));
	if ((*root)->n > value)
	{
		(*root)->left = avl_insert_recursive(&(*root)->left, *root, new, value);
		if ((*root)->left == NULL)
			return (NULL);
	}
	else if ((*root)->n < value)
	{
		(*root)->right = avl_insert_recursive(&(*root)->right, *root, new, value);
		if ((*root)->right == NULL)
			return (NULL);
	}
	else
		return (*root);

	balance = get_balance(*root);
	if (balance > 1 && (*root)->left->n > value)
		*root = binary_tree_rotate_right(*root);
	else if (balance < -1 && (*root)->right->n < value)
		*root = binary_tree_rotate_left(*root);
	else if (balance > 1 && (*root)->left->n < value)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance < -1 && (*root)->right->n > value)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}
	return (*root);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}

