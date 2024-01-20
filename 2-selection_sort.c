#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers using the selection sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || !size)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = size - 1, min = i + 1; j > i; j--)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (array[i] > array[min])
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
