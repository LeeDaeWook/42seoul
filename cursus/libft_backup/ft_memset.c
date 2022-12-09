/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:16:06 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 21:27:55 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void*ptr, int c, size_t len)
{
	unsigned int	i;
	char			*char_ptr;

	if (len > (unsigned int)ft_strlen(ptr))
		return (0);
	i = 0;
	char_ptr = (char *)ptr;
	while (i < len)
		char_ptr[i++] = (unsigned char)c;
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
//	char arr[] = "seoul";
	int arr2[10];
	int num = 3;
//	printf("memset: %s\n", memset(arr, 'c', 10 * sizeof(char)));
//	printf("ft_memset: %s\n", ft_memset(arr, 'c', 10 * sizeof(char)));

	memset(arr2, 1, num * sizeof(int));	
	for (int i = 0; i < num; i++)
		printf("memset: %d\n", arr2[i]);

	ft_memset(arr2, 1, num * sizeof(int));
	for (int i = 0; i < num; i++)
		printf("ft_memset: %d\n", arr2[i]);

	return (0);
}
*/
