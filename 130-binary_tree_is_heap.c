#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - checks a binary tree root as max value
 * @tree: pointer to root
 * Return: 1, if all nodes are max, else 0
 **/

int check_max(const binary_tree_t *tree)
{
	int temp1 = 1, temp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temp1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temp2 = check_max(tree->right);
	}
	return (temp1 && temp2);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: tree to check
 * Return: 1, if it is BTS or  0, otherwise
 **/

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int temp;

	if (!tree)
		return (0);

	temp = binary_tree_is_complete(tree);
	if (!temp)
		return (0);
	return (check_max(tree));
}
