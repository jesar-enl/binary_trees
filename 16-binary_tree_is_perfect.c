#include "binary_trees.h"

/**
 * is_perfect - check if perfect
 * @tree: tree to look at
 * Return: 0 if not, 1 if true
 */
int is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + is_perfect(tree->left);
		r = 1 + is_perfect(tree->right);

		if (r == l && r != 0 && l != 0)
			return (r);
		return (0);
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

/**
 * binary_tree_is_perfect - perfect or not
 * @tree: tree to look at
 * Return: 1 if true
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int res = 0;

	if (tree == NULL)
	{
		return (0);
	}
	res = is_perfect(tree);
	if (res != 0)
		return (1);
	return (0);
}
