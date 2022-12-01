/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:42:00 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 21:02:53 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	while ((i + 1) < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while ((i + 1) <= size)
	{
		dest[i] = '\0';
		i++;
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>
int main(void)
{
	char	dest[] = "abcde";
	const char	src[] = "12345";

	printf("%zu\n", ft_strlcpy(dest, src, 3));

	return (0);
}
*/
