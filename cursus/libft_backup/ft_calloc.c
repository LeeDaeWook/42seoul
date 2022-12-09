/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:47:55 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 21:39:01 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size * count);
	return ((void *)ptr);
}
/*
#include <stdio.h>

int main(void)
{
	char *s1;
	char *s2;
	printf("calloc: %s\n", (char*)calloc(5, sizeof(char))); 
	s2 = (char*)ft_calloc(5, sizeof(char)); 
	printf("ft_calloc: %d\n", s2[0]); 
	s1 = (char*)malloc(5 * sizeof(char));
	printf("malloc: %d\n", s1[0]);

	return (0);
}
*/
