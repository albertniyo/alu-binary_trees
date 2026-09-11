#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a inary tree in pre-order.
 * @tree: pointer to the root node.
 * @func: pointer to a function that calls each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
