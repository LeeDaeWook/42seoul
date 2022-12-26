#include "ft_show_tab.c"

void	ft_show_tab(struct s_stock_str *par);

int main()
{

	char *av[] = {"apple", "blueberry", "orange"};

	t_stock_str *ptr;

	ptr = ft_strs_to_tab(3, av);
	ft_show_tab(ptr);
	return (0);
}

