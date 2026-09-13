#include "binary_trees.h"

/**
 * binary_tree_rotate_left - permors a left-rotation on a binary tree.
 * @tree: pointer to the root.
 *
 * Return: pointer to the new root.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree && tree->right)
	{
		tree->parent = tree->right;
		tree->right = tree->right->left;
		tree->parent->left = tree;
		if (tree->right)
			tree->right->parent = tree;
		tree->parent->parent = NULL;
		return (tree->parent);
	}
	return (NULL);
}
