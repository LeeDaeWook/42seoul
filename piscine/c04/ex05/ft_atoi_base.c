/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:29:11 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/06 20:28:49 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_abase(char *base)
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

int	baselen(char *base)
{
	int	base_len;
	int	i;

	base_len = 0;
	i = 0;
	if (check_abase(base))
	{
		while (*(base + i))
		{
			base_len++;
			i++;
		}
	}
	return (base_len);
}

int	return_idx(char str, char *base)
{
	int	idx;

	idx = 0;
	while (*(base + idx) != '\0')
	{
		if (str == *(base + idx))
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_len;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	base_len = baselen(base);
	while (*str && return_idx(*str, base) != -1 && base_len != 0)
	{
		result = result * base_len + return_idx(*str, base);
		str++;
	}
	result *= sign;
	return (result);
}
