#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to root of the tree.
 *
 * Return: 1 if is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int r = 0, l = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
	{
		l = binary_tree_is_full(tree->left);
		r = binary_tree_is_full(tree->right);
	}
	if (l == r && l == 1)
		return (1);
	return (0);
}
