/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:38:40 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/02 22:45:44 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_lowercase(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

int	ft_str_is_lowercase(char *str)
{
	int	flag;
	int	len;

	flag = 0;
	len = ft_count_lowercase(str);
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
				flag++;
		str++;
	}
	if (flag == len)
		return (1);
	return (0);
}
