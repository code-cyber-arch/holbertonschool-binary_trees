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
	binary_tree_t *p_first, *p_second;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	p_first = first->parent, p_second = second->parent;
	if (first == p_second || !p_first || (!p_first->parent && p_second))
		return (binary_trees_ancestor(first, p_second));
	else if (p_first == second || !p_second || (!p_second->parent && p_first))
		return (binary_trees_ancestor(p_first, second));
	return (binary_trees_ancestor(p_first, p_second));
}

