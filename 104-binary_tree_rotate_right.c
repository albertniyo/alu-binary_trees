#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root.
 *
 * Return: pointer to the new root.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;
	binary_tree_t *parent;

	if (tree && tree->left)
	{
		pivot = tree->left;
		parent = tree->parent;

		tree->left = pivot->right;
		if (tree->left)
			tree->left->parent = tree;

		pivot->right = tree;
		pivot->parent = parent;
		tree->parent = pivot;

		if (parent)
		{
			if (parent->left == tree)
				parent->left = pivot;
			else
				parent->right = pivot;
		}

		return (pivot);
	}
	return (NULL);
}
