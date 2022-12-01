/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:13:18 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 20:03:28 by daewoole         ###   ########.fr       */
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
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == new_c)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && c == '\0' && i < n)
		return (&str[i]);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	//char str[50] = "hello, my name is 42";
	char str[50] = "\0";

	printf("memchr: %s\n", memchr(str, '\0', 21));
	printf("ft_memchr: %s\n", ft_memchr(str, '\0', 21));
	
	return (0);
}
*/
