#include "binary_trees.h"
/**
 * binary_tree_depth - Measures the depth of specified node from root
 * @tree: node to check the depth
 * Return: If tree is NULL, must return 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
