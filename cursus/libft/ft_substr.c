/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:59:39 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/26 21:24:37 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen((char *)s) <= start)
	{
		str = (char *)malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) - start + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
