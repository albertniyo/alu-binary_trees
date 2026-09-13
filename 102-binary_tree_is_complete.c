#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: a size_t value of the size, if tree is NULL return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t right_size = 0, left_size = 0;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	if (tree->left)
		left_size = binary_tree_size(tree->left);
	if (tree->right)
		right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}

/**
 * aux_complete - chec if a binary tree is complete.
 * @tree: pointer to root node of a tree.
 * @idx: index of a node.
 * @n_node: number of node of the binary tree.
 *
 * Return: 1 if is complete, 0 otherwise.
 */
int aux_complete(const binary_tree_t *tree, int idx, int n_node)
{
	int left = 0, right = 0;

	if (!tree)
		return (1);

	if (idx >= n_node)
		return (0);
	left = aux_complete(tree->left, (2 * idx + 1), n_node);
	right = aux_complete(tree->right, (2 * idx + 2), n_node);

	return (left * right);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int n_node = 0; /* Number of nodes. */
	int complete = 0; /* Is complete. */

	if (!tree)
		return (0);

	n_node = binary_tree_size(tree);

	complete = aux_complete(tree, 0, n_node);

	return (complete);
}
