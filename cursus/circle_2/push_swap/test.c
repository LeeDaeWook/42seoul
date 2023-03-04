#include "push_swap.h"
#include <stdio.h>

void test(int *count)
{
    count[0] = 3;
}

int main()
{
    int count;

    count = 5;
    test(&count);
    printf("%d\n", count);

    return (0);
}