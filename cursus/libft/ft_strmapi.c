/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:24:56 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 22:06:02 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}	
/*
char	ft_strupcase(unsigned int i, char c)
{
	(void) i;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

#include <stdio.h>

int main(void)
{
	char s[] = "abcde";
	printf("%s\n", ft_strmapi(s, ft_strupcase));

	return (0);
}
*/
