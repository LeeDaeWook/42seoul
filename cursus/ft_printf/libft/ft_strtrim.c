/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:28:22 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/26 21:23:46 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
	size_t	front;
	size_t	back;

	front = 0;
	back = ft_strlen((char *)s1);	
	while (s1[front] && is_set(s1[front], set))
		front++;
	while (s1[back - 1] && is_set(s1[back - 1], set) && back > front)
		back--;
	str = (char *)malloc(sizeof(char) * (back - front + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, &s1[front], back - front + 1);
	return (str);
}
