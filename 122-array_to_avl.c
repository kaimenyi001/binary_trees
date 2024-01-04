#include "binary_trees.h"
/**
 * array_to_avl - function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: size of array
 * Return: root node of the created AVL, or NULL upon failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j = 0;
	avl_t *root = NULL;

	if (size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&root, array[i]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
