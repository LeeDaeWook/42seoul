/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:39:53 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 20:06:08 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;

	if (dst == src || len == 0)
		return (dst);
	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;
	if (dst_ptr <= src_ptr)
	{
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	else
	{
		dst_ptr += (len - 1);
		src_ptr += (len - 1);
		while (len--)
			*dst_ptr-- = *src_ptr--;
	}
	return (dst);
}
/*
#include <string.h>

int main(void)
{
	char dst1[] = "abcdefghi";
	char dst2[] = "abcdefghi";
	//char src[] = "123456789";
	//printf("memmove: %s\n", memmove(dst1 + 2, dst1, sizeof(dst1)));
	printf("ft_memmove: %s\n", ft_memmove(dst2 + 2, dst2, sizeof(dst1)));

	return (0);
}
*/
