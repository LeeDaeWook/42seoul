/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:29:01 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 21:36:24 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	int				temp;
	char			*new_str;

	new_str = (char *)str;
	i = 0;
	j = 0;
	if (!(*needle))
		return (new_str);
	while (*(new_str + j) != '\0' && j < len)
	{
		if (*(needle + i) == *(new_str + j))
		{
			if (i == 0)
				temp = j;
			i++;
			if (*(needle + i) == '\0')
				return (new_str + temp);
		}
		else
			i = 0;
		j++;
	}
	return (0);
}
