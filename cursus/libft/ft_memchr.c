/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:13:18 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/26 21:17:28 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	new_c;
	char			*str;
	unsigned int	i;

	new_c = (unsigned char)c;
	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == new_c)
			return (&str[i]);
		i++;
	}
	return (0);
}
