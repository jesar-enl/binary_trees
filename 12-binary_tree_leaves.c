#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in the tree
 * @tree: tree to consider
 * Return: the leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		leaf = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
		
		if (!(binary_tree_leaves(tree->left)) && !(binary_tree_leaves(tree->right)))
		{
			return leaf + 1;
		}
		else
		{
			return leaf + 0;
		}
	}
}
