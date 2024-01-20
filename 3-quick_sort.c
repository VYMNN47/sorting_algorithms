#include "sort.h"

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

void quicksort_helper(int *array, size_t size, ssize_t min, ssize_t max)
{
	if (min < max)
	{
		size_t piv = lomuto_part(array, size, min, max);

		quicksort_helper(array, size, min, piv - 1);
		quicksort_helper(array, size, piv + 1, max);
	}
}

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}

	quicksort_helper(array, size, 0, size - 1);
}
