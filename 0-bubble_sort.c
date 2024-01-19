#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble Sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{

	int swapped = 1; /* Initialize swapped to 1 to enter the loop */
	size_t i;
	int temp;

	while (swapped)
	{
		swapped = 0; /* Reset swapped before each iteration */

		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				/* Swap elements */
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				swapped = 1; /* Set swapped to 1 to continue the loop */
				print_array(array, size);
			}
		}
	}
}
