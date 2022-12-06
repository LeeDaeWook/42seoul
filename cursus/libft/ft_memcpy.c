/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:48:12 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 21:42:23 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (n > (size_t)ft_strlen((char *)dst) \
			|| n > (size_t)ft_strlen((char *)src))
		return (0);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	while ((i + 1) < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//char dst[10];
	char dst[] = "abcde";
	const char src[] = "12345";
	//printf("memcpy: %s\n", memcpy(dst, src, 10));
	printf("ft_memcpy: %s\n", ft_memcpy((void*)dst, (void*)src, 10));

	return (0);
}
*/
