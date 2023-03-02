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
        binary_tree_t *t1, *t2;

        if (first == NULL || second == NULL)
                return (NULL);

        if (first == second)
                return ((binary_tree_t *)first);

        t1 = first->parent;
        t2 = second->parent;
        if (t1 == NULL || first == t2 || (!t1->parent && t2))
        {
                return (binary_trees_ancestor(first, t2));
        }
        else if (t2 == NULL || t1 == second || (!t2->parent && t1))
        {
                return (binary_trees_ancestor(t1, second));
        }
        return (binary_trees_ancestor(t1, t2));
}
