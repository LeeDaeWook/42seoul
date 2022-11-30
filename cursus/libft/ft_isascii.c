/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:39:34 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/12 19:14:06 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_isascii(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

int	ft_isascii(char *str)
{
	int	flag;
	int	len;

	flag = 0;
	len = ft_count_isascii(str);
	while (*str != '\0')
	{
		if (*str >= 0 && *str <= 127)
				flag++;
		str++;
	}
	if (flag == len)
		return (1);
	return (0);
}
