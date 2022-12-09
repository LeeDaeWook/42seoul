/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:42:53 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 22:06:39 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	if (!(*to_find))
		return ((char *)str);
	while (*(str + j) != '\0')
	{
		if (*(to_find + i) == *(str + j))
		{
			if (i == 0)
				temp = j;
			i++;
			if (*(to_find + i) == '\0')
				return ((char *)(str + temp));
		}
		else
			i = 0;
		j++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	const char	s1[] = "abcde";
	const char	s2[] = "cd";
	printf("%s\n", ft_strstr(s1, s2));
	return (0);
}
*/
