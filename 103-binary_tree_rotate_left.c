#include "binary_trees.h"

/**
 * binary_tree_rotate_left - permors a left-rotation on a binary tree.
 * @tree: pointer to the root.
 *
 * Return: pointer to the new root.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;
	binary_tree_t *parent;

	if (tree && tree->right)
	{
		pivot = tree->right;
		parent = tree->parent;

		tree->right = pivot->left;
		if (tree->right)
			tree->right->parent = tree;

		pivot->left = tree;
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
