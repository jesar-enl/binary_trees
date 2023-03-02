#include "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowect common ancestor of two nodes
 * @first: node 1
 * @second: node 2
 * Return: LCA
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor;
	binary_tree_t *tmp1 = (binary_tree_t *)first;
	binary_tree_t *tmp2 = (binary_tree_t *)second;

	if (first == NULL || second == NULL)
		return (NULL);

	while (tmp1 != NULL)
	{
		ancestor = tmp2;
		while (ancestor != NULL)
		{
			if (ancestor == tmp1)
				return (ancestor);
			ancestor = ancestor->parent;
		}
		tmp1 = tmp1->parent;
	}
	return (NULL);
}
