/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:39:34 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/12 19:15:17 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_isprint(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

int	ft_isprint(char *str)
{
	int	flag;
	int	len;

	flag = 0;
	len = ft_count_isprint(str);
	while (*str != '\0')
	{
		if (*str >= 32 && *str <= 126)
				flag++;
		str++;
	}
	if (flag == len)
		return (1);
	return (0);
}
