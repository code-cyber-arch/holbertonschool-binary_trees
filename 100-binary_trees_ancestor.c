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
	binary_tree_t *p_first = first->parent;
	binary_tree_t *p_second;

	while (p_first)
	{
		p_second = second->parent;
		while (p_second)
		{
			if (p_first == p_second)
				return (p_first);

			p_second = p_second->parent;
		}
		p_first = p_first->parent;
	}
	return (NULL);
}

