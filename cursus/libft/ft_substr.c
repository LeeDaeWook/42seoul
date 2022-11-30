/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:59:39 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/30 13:18:22 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	substr = (char *)malloc(sizeof(char) * len);
	if (!substr)
		return (0);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	return (substr);
}

/*
#include <stdio.h>

int main(void)
{	
	char	s[] = "abcdefghijklmnopq";
	printf("%s\n", ft_substr(s, 3, 5));

	return (0);
}
*/
