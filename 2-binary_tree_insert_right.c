#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a new node     to the left of the tree
 * @parent: the parent node
 * @value: the adta of the node
 * Return: new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newn;

	if (parent == NULL)
		return (NULL);

	newn = binary_tree_node(parent, value);
	if (newn == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		newn->right = parent->right;
		parent->right->parent = newn;
	}
	parent->right = newn;
	return (newn);
}
