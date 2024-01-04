#include "binary_trees.h"
/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node, NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
