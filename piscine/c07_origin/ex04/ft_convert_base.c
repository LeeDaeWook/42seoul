#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	if (!(*base) || !(*(base + 1)))
		return (0);
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		if (*(base + i) == *(base + i + 1))
			return (0);
		if (*(base + i) == ' ' || (*(base + i) >= 9 && *(base + i) <= 13))
			return (0);
		i++;
	}
	return (1);
}

int	ft_base(char *base)
{
	int	base_len;
	int	i;

	base_len = 0;
	i = 0;
	if (ft_check_base(base))
	{
		while (*(base + i))
		{
			base_len++;
			i++;
		}
	}
	return (base_len);
}

int	ft_return_index(char str, char *base)
{
	int	index;

	index = 0;
	while (*(base + index) != '\0')
	{
		if (str == *(base + index))
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	long	l;
	int		sign;
	int		base_len;

	l = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	base_len = ft_base(base);
	while (*str && (ft_return_index(*str, base) != -1) && base_len != 0)
	{
		l = (l * base_len) + ft_return_index(*str, base);
		str++;
	}
	l *= sign;
	return ((int) l);
}

int check_base(char *base)
{
	int	i;

	i = 0;
	if (!(*base) || !(*(base + 1)))
		return (0);
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);	
		if (*(base + i) == *(base + i + 1))
			return (0);
		i++;
	}
	return (1);
}

void	ft_rev_char_tab(char *tab, int size)
{
	int	i;
	char	temp;
	int	len;

	if (tab[0] == '-')
	{
		i = 1;
		len = (size - 1) / 2 + 1;
	}
	else
	{
		i = 0;
		len = size / 2;
	}
	while (i < len) 
	{
		temp = tab[size - 1];
		tab[size - 1] = tab[i];
		tab[i] = temp;
		i++;
		size--;
	}
}

void	ft_putnbr_base(int int_from, char *base_to, char *result, int idx, int *len)
{
	int		base_len;

	base_len = 0;
	if (int_from == 0)
	{
		result[0] = base_to[0];
		return ;
	}
	while (*(base_to + base_len))
		base_len++;
	if (int_from < 0)
	{
		result[idx++] = '-';
		int_from *= -1;
		*len += 1;
	}
	if (int_from > 0)
	{
		result[idx] = base_to[int_from % base_len];
		*len += 1;
		if ((int_from / base_len) == 0)
			return ;
		ft_putnbr_base(int_from / base_len, base_to, result, idx + 1, len);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		int_from;
	char		*result;
	int 		result_len;

	result_len = 0;
	result = (char*)malloc(sizeof(char) * 50);	
	if (!(int_from = ft_atoi_base(nbr, base_from)))
		return (0);
	if (int_from < 0)
	if (!(check_base(base_to)))
		return (0);
	ft_putnbr_base(int_from, base_to, result, 0, &result_len);
	ft_rev_char_tab(result, result_len);

	return (result);
}


int	main()
{
{
	char *str = "-123456789";
	char *base_from = "0123456789";
	char *base_to = "0123456789abcdef";
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}

{
	char *str = "100100111";
	char *base_from = "01";
	char *base_to = "0123456789";
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}

/*
{
	char *str = "0";
	char *base_from = "0123456789";
	char *base_to = "01";
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
{
	char *str = "-1";
	char *base_from = "0123456789";
	char *base_to = "01";
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
{
	char *str = "-2";
	char *base_from = "0123456789";
	char *base_to = "01";
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
{
	char *str = "2";
	char *base_from = "0123456789";
	char *base_to = "01";
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
{
	char *str = "-2147483648";
	char *base_from = "0123456789";
	char *base_to = "01";
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
{
	char *str = "101";
	char *base_from = "";
	char *base_to = "24";

	printf("base error check\n\n");
	printf("case 1.  base is empty or size of 1 \2n");
	printf("base size = 0\n");
	printf("result = ");
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
{
	char *str = "101";
	char *base_from = "1";
	char *base_to = "23";
	printf("base size = 1\n");
	printf("result = ");
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
{
	char *str = "101";
	char *base_from = "01";
	char *base_to = "012345667";
	printf("\ncase 2. base contains the same character twice\n\n");
	printf("base = 012345667\n");
	printf("result = ");
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
{
	char *str = "101";
	char *base_from = "01";
	char *base_to = "-01234567";
	printf("\ncase 3.base contains + or - \n\n");
	printf("base = -01234567\n");
	printf("result = ");
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
{
	char *str = "101";
	char *base_from = "01";
	char *base_to = "0123 4567";
	printf("\ncase 4 whitespaces\n\n");
	printf("base = 0123 4567\n");
	printf("result = ");
	printf("%s\n", ft_convert_base(str, base_from, base_to));
}
*/
}
