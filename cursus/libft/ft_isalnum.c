/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:45:58 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 21:31:55 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(char *str)
{
	size_t	flag;
	size_t	len;

	flag = 0;
	len = ft_strlen(str);
	while (*str != '\0')
	{
		if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')
			|| (*str >= '0' && *str <= '9'))
			flag++;
		str++;
	}
	if (flag == len)
		return (1);
	return (0);
}
