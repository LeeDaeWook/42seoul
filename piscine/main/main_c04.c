#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"
#include <stdio.h>
#include <string.h>

int main(void)
{
	{
	printf("ex00");
	printf("\n");
	char s[100] = "abcde";
	printf("%d %lu", ft_strlen(s), strlen(s));
	printf("\n");
	}
	{
	printf("ex01");
	printf("\n");
	char s[100] = "abcde";
	ft_putstr(s);
	printf("\n");
	}
	{
	printf("ex02");
	printf("\n");
	int i = 12345;
	ft_putnbr(i);
	printf("\n");
	}
	{
	printf("ex03");
	printf("\n");
	char s[100] = "  ---+--+1234ab567";
	printf("%d", ft_atoi(s));
	printf("\n");
	}
	{
	printf("ex04");
	printf("\n");
	char base[100] = "0123456789";
	ft_putnbr_base(12345, base);
	printf("\n");
	}
	{
	printf("ex05");
	printf("\n");
	char s[100] = "55512351";	
	char base[100] = "0123456789abcdef";
	printf("%d", ft_atoi_base(s, base));
	printf("\n");
	}
}	
