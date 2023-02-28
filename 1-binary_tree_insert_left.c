#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a new node to the left of the tree
 * @parent: the parent node
 * @value: the adta of the node
 * Return: new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newn = binary_tree_node(parent, value);

	if (newn == NULL)
		return (NULL);
	if (parent == NULL)
		return (NULL);


	if (parent->left != NULL)
	{
		newn->left = parent->left;
		parent->left->parent = newn;
	}
	parent->left = newn;
	return (newn);
}
