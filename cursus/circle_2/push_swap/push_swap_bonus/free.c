#include "push_swap.h"

void free_count(int **count, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(count[i]);
        i++;
    }
    free(count);
}