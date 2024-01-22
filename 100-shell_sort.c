#include "sort.h"

int get_gap(size_t size)
{
    
    size_t seq = 1;
    size_t prev_seq;
    
    while (1)
    {
        if (size <= seq)
        {
            return(prev_seq);
        }
        prev_seq = seq;
        seq = seq * 3 + 1;
    }
    
    return 0;
}

void shell_sort(int *array, size_t size)
{
    size_t i;
    int j;
    int tmp, gap;
    for (gap = get_gap(size); gap > 0; gap = (gap - 1) / 3)
    {
        for (i = gap; i < size; i++)
        {
            tmp = array[i];
            for (j = i; j >= gap; j -= gap)
            {
                if (tmp < array[j - gap])
                {
                    array[j] = array[j - gap];
                } else
                {
                    break;
                }
            }
            array[j] = tmp;
        }
        print_array(array, size);
    }
}
