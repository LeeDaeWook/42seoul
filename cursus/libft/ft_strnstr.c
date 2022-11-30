/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:29:01 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/17 16:45:57 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	int	temp;
	char	*str;

	str = (char*)haystack;
	i = 0;
	j = 0;
	if (!(*needle))
		return (str);
	while (*(str + j) != '\0' && j < len)
	{
		if (*(needle + i) == *(str + j))
		{
			if (i == 0)
				temp = j;
			i++;
			if (*(needle + i) == '\0')
				return (str + temp);
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
	char haystack[] = "hello, here is 42seoul's cluster";
	char needle[] = "flsdksjkldsjf";
	printf("strnstr: %s\n", strnstr(haystack, needle, -5));
	printf("ft_strnstr: %s\n", ft_strnstr(haystack, needle, -5));

	return (0);
}
*/
