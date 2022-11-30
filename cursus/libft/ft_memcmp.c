/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:34:41 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/30 13:28:51 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

unsigned int	ft_check_len(unsigned char *s1, unsigned char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (i < j)
		return (j);
	return (i);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	unsigned int	i;
	int				diff;

	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && i < ft_check_len(new_s1, new_s2))
	{
		diff = (new_s1[i] - new_s2[i]);
		if (new_s1[i] > new_s2[i])
			return (diff);
		else if (new_s1[i] < new_s2[i])
			return (diff);
		else if (new_s1[i] == new_s2[i])
			i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	char s1[] = "abcde\200";
	char s2[] = "abcde\10";
	printf("memcmp: %d\n", memcmp(s1, s2, 6));
	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, 6));

	return (0);
}
*/
