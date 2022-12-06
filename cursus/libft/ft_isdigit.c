/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:54:19 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 19:55:11 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(char *str)
{
	int	flag;
	int	len;

	flag = 0;
	len = ft_strlen(str);
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
				flag++;
		str++;
	}
	if (flag == len)
		return (1);
	return (0);
}
