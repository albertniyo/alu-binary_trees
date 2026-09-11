#include "binary_trees.h"

/**
 * binary_tree_depth - calculate the depth inside the tree
 * @tree: pointer to the node.
 *
 * Return: size of depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t i = 0;

	if (tree == NULL || (tree->parent == NULL))
		return (0);
	i = 1 + binary_tree_depth(tree->parent);
	return (i);
}
