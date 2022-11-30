/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:28:22 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/30 13:18:45 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

unsigned int	ft_strlen(char const *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (is_set(s1[i], set))
			i++;
		else
			str[j++] = s1[i++];
	}
	return (str);
}

/*
#include <stdio.h>

int main(void)
{
	char s1[] = ":,abcDEF";
	char set[] = ":,aF";
	printf("%s\n", ft_strtrim(s1, set));

	return (0);
}
*/
