#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 */

void swap(int *array, size_t size, int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_part - Performs the Lomuto partition scheme for quicksort.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * @min: Minimum index for partitioning.
 * @max: Maximum index for partitioning.
 *
 * Return: (i) the index where the pivot is
 */

size_t lomuto_part(int *array, size_t size, ssize_t min, ssize_t max)
{
	int i, j, piv = array[max];

	for (i = j = min; j < max; j++)
	{
		if (array[j] < piv)
		{
			swap(array, size, &array[j], &array[i++]);
		}
	}
	swap(array, size, &array[i], &array[max]);

	return (i);
}

/**
 * quicksort_helper - Recursive helper function for quicksort.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * @min: Minimum index for sorting.
 * @max: Maximum index for sorting.
 *
 */

void quicksort_helper(int *array, size_t size, ssize_t min, ssize_t max)
{
	if (min < max)
	{
		size_t piv = lomuto_part(array, size, min, max);

		quicksort_helper(array, size, min, piv - 1);
		quicksort_helper(array, size, piv + 1, max);
	}
}

/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 *
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}

	quicksort_helper(array, size, 0, size - 1);
}
