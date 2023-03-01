#include "binary_trees.h"

/**
 * binary_tree_is_full - check if tree is full
 * @tree: tree to traverse
 * Return: 1 for true
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left && tree->right)
		{
			l = binary_tree_is_full(tree->left);
			r = binary_tree_is_full(tree->right);

			if (l == 0 || r == 0)
			{
				return (0);
			}
			return (1);
		}
		else if (!tree->left && !tree->right)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}
