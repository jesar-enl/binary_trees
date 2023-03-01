#include "binary_trees.h"

/**
 * binary_tree_size - find the size of the tree
 * (number of nodes in the tree)
 * @tree: the tree to traverse
 * Return: the size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		size = binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;
	}
	return (size);
}
