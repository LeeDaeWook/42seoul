#include <stdlib.h>
#include <stdio.h>
#include "ft_strs_to_tab.c"

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

int main()
{
	int i;

	i = 0;

	char *av[] = {"apple", "blueberry", "orange"};

	t_stock_str *ptr;

	ptr = ft_strs_to_tab(3, av);
	while (i < 3)
	{
		printf("%d ", ptr[i].size);
		printf("%s ", ptr[i].str);
		printf("%s\n", ptr[i].copy);
		//ptr++;
		i++;
	}
	
	return (0);
}
