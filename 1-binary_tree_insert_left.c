#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert left node to a binary tree
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: left node to the parent, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	if (parent->left != NULL)
	{
		node->left = parent->left;
		node->left->parent = node;
	}

	parent->left = node;

	return (node);
}
