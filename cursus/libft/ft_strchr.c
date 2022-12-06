/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:43:40 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 21:44:26 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == '\0' && c == '\0')
		return (str);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[50] = "hello, my name is 42";
	//char str[50] = "\0";

	printf("strchr: %s\n", strchr(str, 'o'));
	printf("ft_strchr: %s\n", ft_strchr(str, 'o'));
	
	return (0);
}
*/
