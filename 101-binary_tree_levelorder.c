#include "binary_trees.h"

/**
 * binary_tree_height - find the height of the tree
 * @tree: tree to traverse
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);

	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	}
	return ((l > r) ? l : r);
}

/**
 * binary_tree_depth - calculate the depth of the tree
 * @tree: tree to traaverse
 * Return: the depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
	{
		return (1 + binary_tree_depth(tree->parent));
	}
	else
	{
		return (0);
	}
}

/**
 * linked_node - create a linkd list
 * @head: head pointer
 * @tree: tree used
 * @l: depth of tree
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t l)
{
	link_t *new, *aux;

	new = malloc(sizeof(link_t));
	if (new == NULL)
		return;

	new->n = l;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		new->next = NULL;
		aux->next = new;
	}
}

/**
 * recursion - recursive traversion
 * @head: pointer to head of linked list
 * @tree: tree used
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t l = 0;

	if (tree != NULL)
	{
		l = binary_tree_depth(tree);
		linked_node(head, tree, l);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - print node elements in level-order
 * @tree: tree to traverse
 * @func: function to use
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t h = 0, c = 0;

	if (!tree || !func)
		return;

	h = binary_tree_height(tree);
	head = NULL;
	recursion(&head, tree);
	while (c <= h)
	{
		aux = head;
		while (aux != NULL)
		{
			if (c == aux->n)
			{
				func(aux->node->n);
			}
			aux = aux->next;
		}
		c++;
	}
	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
