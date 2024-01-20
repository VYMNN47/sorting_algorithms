#include "sort.h"


void swap(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

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
