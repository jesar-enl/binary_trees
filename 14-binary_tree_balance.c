#include "binary_trees.h"

/**
 * binary_tree_height_a - measure the height of the balance tree
 * @tree: tree to traverse
 * Return: height
 */
size_t binary_tree_height_a(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height_a(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height_a(tree->right) : 1;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - check if tree is balanced
 * @tree: tree to traverse
 * Return: balance factior
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int r = 0, l = 0;

	if (tree)
	{
		l = (int)binary_tree_height_a(tree->left);
		r = (int)binary_tree_height_a(tree->right);
	}
	return (l - r);
}
