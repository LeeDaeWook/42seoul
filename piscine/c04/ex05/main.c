#include <stdio.h>
#include "ft_atoi_base.c"

int main()
{
	char *base = "0123456789abcdef";
	char *str = "123456";
	printf("%d", ft_atoi_base(str, base));
}
