#include "libft.h"

char	*uppercase(char *str)
{
	char	*new_base;
	int	i;

	i = 0;
	new_base = (char*)malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			new_base[i] = str[i] - 32;
		else
			new_base[i] = str[i];
		i++;
	}
	return (new_base);
}

void	ft_putnbr_base(unsigned long long nbr, int *ret_val, char *format)
{
	int		base_len;
	char	c;
	char	*base;

    base = "0123456789abcdef";
	if (*format == 'X')
		base = uppercase(base);
	base_len = 0;
	while (*(base + base_len))
		base_len++;
	c = base[nbr % base_len];
	*ret_val += 1;
	if ((nbr / base_len) == 0)
	{
		write(1, &c, 1);
		return ;
	}
	ft_putnbr_base(nbr / base_len, ret_val, format);
	write(1, &c, 1);
}
