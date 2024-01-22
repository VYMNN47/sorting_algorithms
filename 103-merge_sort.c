#include "sort.h"

/**
 * merge_compare - Merge two halves of an array.
 * @array: The array to be merged.
 * @first: Index of the first element.
 * @last: Index of the last element.
 * @array_cp: Temporary array for merging.
 */

void merge_compare(int *array, size_t first, size_t last, int *array_cp)
{
	size_t x = first, i, j, mid;

	i = mid = (first + last) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + first, mid - first);
	printf("[right]: ");
	print_array(array + mid, last - mid);
	for (j = first; j < last; j++)
		if (x < mid && (i >= last || array[x] <= array[i]))
		{
			array_cp[j] = array[x++];
		}
		else
		{
			array_cp[j] = array[i++];
		}
	printf("[Done]: ");
	print_array(array_cp + first, last - first);
}

/**
 * merge - Recursively merge sort an array.
 * @array: The array to be sorted.
 * @first: Index of the first element.
 * @last: Index of the last element.
 * @array_cp: Temporary array for merging.
 */

void merge(int *array, size_t first, size_t last, int *array_cp)
{
	size_t mid;

	mid = (first + last) / 2;
	if (last - first < 2)
	{
		return;
	}
	merge(array_cp, first, mid, array);
	merge(array_cp, mid, last, array);
	merge_compare(array, first, last, array_cp);
}

/**
 * merge_sort - Sort an array using merge sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */

void merge_sort(int *array, size_t size)
{
	int *array_cp;
	size_t x;

	if (!array || size < 2)
		return;

	array_cp = malloc(sizeof(int) * size);
	if (!array_cp)
		return;
	for (x = 0; x < size; x++)
		array_cp[x] = array[x];
	merge(array_cp, 0, size, array);
	free(array_cp);
}
