/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:39:08 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/02 22:46:10 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_uppercase(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

int	ft_str_is_uppercase(char *str)
{
	int	flag;
	int	len;

	flag = 0;
	len = ft_count_uppercase(str);
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
				flag++;
		str++;
	}
	if (flag == len)
		return (1);
	return (0);
}
