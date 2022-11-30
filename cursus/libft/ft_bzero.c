/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:12:48 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/12 20:33:49 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void	*ft_memset(void*ptr, int c, size_t len)
{
	unsigned char	unchar;
	unsigned int	i;
	char			*char_ptr;

	if (len > (unsigned int)ft_strlen(ptr))
		return (0);
	unchar = (unsigned char)c;
	i = 0;
	char_ptr = (char *)ptr;
	while (i < len)
		char_ptr[i++] = unchar;
	return (ptr);
}

void	ft_bzero(void*s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
void ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char* ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
		ptr[i++] = 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

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
