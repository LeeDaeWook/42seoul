#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char    s[] = "abc";
    int output1;
    int output2;
    unsigned int    un = 2147483649;
    char    num[] = "12345";

    output1 = printf("printf:   %.5d\n", 15000);
    printf("output of printf: %d\n", output1);

    output2 = ft_printf("ft_printf:%-10d\n", 1000);
    printf("output of ft_printf: %d\n", output2);

    //t_flag flag;

    //ft_memset_intptr((void*)&flag, 0, sizeof(flag) / 4);
    //printf("flag: %d %d %d %d\n", flag.dot, flag.minus, flag.star, flag.zero);

    return (0);
}