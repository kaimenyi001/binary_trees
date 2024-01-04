#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to check
 * Return: height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((l > r) ? l : r);
		}
}

/**
 * bal_avl - function to compare each subtree if its AVL
 * @tree: node that point to the tree to check
 * @high: node that point to the higher node selected
 * @low: node that point to the lower node selected
 * Return: 1 if tree is AVL, 0 if not
 */

int bal_avl(const binary_tree_t *tree, int low, int high)
{
	size_t height_l, height_r, balancer;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < low)
		{
			return (0);
		}
		height_l = binary_tree_height(tree->left);
		height_r = binary_tree_height(tree->right);
		balancer = height_l > height_r ? height_l - height_r : height_r - height_l;
		if (balancer > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, low, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: root node of the tree to check
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
