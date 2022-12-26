/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:03:46 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/12 18:14:17 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long long	ft_atoi_base(char *str, char *base)
{
	long long	l;
	int			sign;
	int			base_len;

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
	return (l);
}
