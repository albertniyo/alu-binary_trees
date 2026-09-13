#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root.
 *
 * Return: pointer to the new root.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree && tree->left)
	{
		tree->parent = tree->left;
		tree->left = tree->left->right;
		tree->parent->right = tree;
		if (tree->left)
			tree->left->parent = tree;
		tree->parent->parent = NULL;
		return (tree->parent);
	}
	return (NULL);
}
