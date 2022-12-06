/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:42:37 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 22:06:22 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_check_len(char *s1, char *s2)
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
		return (i);
	return (j);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && i < (ft_check_len((char *)s1, (char *)s2) + 1))
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == s2[i])
			i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	const char	s1[] = "abcde";
	const char	s2[] = "12345";

	printf("%d\n", ft_strncmp(s1, s2, 1));

	return (0);
}
*/
