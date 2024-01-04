#include "binary_trees.h"
/**
 * r_insert_node - node value instertion in a AVL
 * @tree: type **pointer of root node of the AVL tree struct
 * @parent: parent node of struct AVL
 * @new: **pointer left or right insertion
 * @ival: insertion value of the AVL
 * Return: pointer to the new root after insertion, otherwise NULL
 */

avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int ival)
{
	int bval;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, ival));
	if ((*tree)->n > ival)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, ival);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < ival)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, ival);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	bval = binary_tree_balance(*tree);
	if (bval > 1 && (*tree)->left->n > ival)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval > 1 && (*tree)->left->n < ival)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval < -1 && (*tree)->right->n < ival)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bval < -1 && (*tree)->right->n > ival)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: **pointer to the root node of the AVL tree to insert into
 * @value: The value to insert into the AVL tree
 * Return: pointer to the inserted node, or NULL on failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new, value);
	return (new);
}
