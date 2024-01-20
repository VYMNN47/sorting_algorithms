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
                min = i;

                for (j = i+1; j < size; j++)
                {
                        if (array[j] < array[min])
                        {
                                min = j;
                        }
                }

                swap(&array[min], &array[i]);
                print_array(array, size);
        }
}
