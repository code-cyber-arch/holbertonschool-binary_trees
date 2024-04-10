#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *p_first = first;
	binary_tree_t *q_first;

	while (p_first)
	{
		q_first = second;
		while (q_first)
		{
			if (p_first == q_first)
				return (p_first);

			q_first = q_first->parent;
		}
		p_first = p_first->parent;
	}
	return (NULL);
}

