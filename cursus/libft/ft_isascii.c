/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:53:02 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 19:53:09 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(char *str)
{
	size_t	flag;
	size_t	len;

	flag = 0;
	len = ft_strlen(str);
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
