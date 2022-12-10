/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:53:22 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 19:53:29 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(char *str)
{
	size_t	flag;
	size_t	len;

	flag = 0;
	len = ft_strlen(str);
	while (*str != '\0')
	{
		if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
			flag++;
		str++;
	}
	if (flag == len)
		return (1);
	return (0);
}
