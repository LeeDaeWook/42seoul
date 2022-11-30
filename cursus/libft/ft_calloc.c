/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:47:55 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/17 17:18:32 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	unsigned int i;

	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	i = 0;
	while (i < count)
		ptr[i++] = 0;
	return ((void*)ptr);
}

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
