/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:55:18 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 19:55:57 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(char *str)
{
	int	flag;
	int	len;

	flag = 0;
	len = ft_strlen(str);
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
