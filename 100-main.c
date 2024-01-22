#include "sort.h"

int main(void)
{
    int array[] = {35, 9, 2, 22, 18, 26, 29, 31, 33, 40, 10, 13, 20, 38, 12, 34, 21, 37, 41, 4, 19, 30, 6, 39, 5, 1, 27, 8, 14, 15, 36, 32, 7, 16, 23, 17, 3, 25, 28, 24, 11};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
