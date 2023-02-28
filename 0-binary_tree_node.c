#include "binary_trees.h"

/**
 * binary_tree_node - create a new node in the tree
 * @parent: parent node of the tree
 * @value: data of the node created
 * Return: new node created
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newn = malloc(sizeof(binary_tree_t));

	if (newn == NULL)
		return (NULL);
	newn->n = value;
	newn->parent = parent;
	newn->left = NULL;
	newn->right = NULL;
	return (newn);
}
