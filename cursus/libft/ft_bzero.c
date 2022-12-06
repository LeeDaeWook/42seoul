/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:38:38 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 21:38:44 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void*s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char* ptr1;
	char* ptr2;
	ptr1 = malloc(sizeof(char) * 10);
	ptr2 = malloc(sizeof(char) * 10);
	bzero(ptr1, 10);
	ft_bzero(ptr2, 10);
	printf("bzero: %s\n", ptr1);
	printf("ft_bzero: %s\n", ptr2);

	return (0);
}
*/
