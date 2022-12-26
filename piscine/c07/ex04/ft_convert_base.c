/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:16 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/13 17:19:13 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int			ft_check_base(char *base);
int			ft_base(char *base);
int			ft_return_index(char str, char *base);
long long	ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
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
	int		i;
	char	temp;
	int		len;

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

void	ft_putnbr_base(long long int_from, char *base_to, char *result, int idx)
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
	}
	if (int_from > 0)
	{
		result[idx] = base_to[int_from % base_len];
		if ((int_from / base_len) == 0)
		{
			result[++idx] = '\0';
			return ;
		}
		ft_putnbr_base(int_from / base_len, base_to, result, idx + 1);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long		int_from;
	char			*result;
	int				result_len;
	int				memory_len;
	long long		div;

	result_len = 0;
	int_from = ft_atoi_base(nbr, base_from);
	if (!check_base(base_to) || !check_base(base_from))
		return (0);
	memory_len = 0;
	div = int_from;
	while (div > 0 || div < 0)
	{
		memory_len++;
		div /= (ft_strlen(base_to));
	}
	result = (char *)malloc(sizeof(char) * (memory_len + 2));
	ft_putnbr_base(int_from, base_to, result, 0);
	result_len = ft_strlen(result);
	ft_rev_char_tab(result, result_len);
	return (result);
}
