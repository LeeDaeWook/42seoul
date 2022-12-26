/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:29:01 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/22 16:53:07 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	temp;

	i = 0;
	j = 0;
	if (!needle || (*str == '\0' && *needle == '\0'))
		return ((char*)str);
	while (str[j] != '\0' && j < len)
	{
		if (needle[i] == str[j])
		{
			if (i == 0)
				temp = j;
			i++;
			if (needle[i] == '\0')
				return ((char*)&str[temp]);
		}
		else if (i > 0)
		{
			j = temp;
			i = 0;
		}
		j++;
	}
	return (0);
}
