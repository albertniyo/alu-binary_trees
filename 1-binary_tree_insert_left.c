#include "binary_trees.h"
/**
 * binary_tree_insert_left - function that inserts a node as the left-child
 * of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 *
 * Return: Pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;
	binary_tree_t *tmp = NULL;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->right = NULL;
	if (parent->left)
	{
		tmp = parent->left;
		parent->left = new;
		new->left = tmp;
		tmp->parent = new;
	}
	else
	{
		parent->left = new;
		new->left = NULL;
	}
	return (new);
}
