/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:29:01 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/02 12:44:09 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	str_len;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)str);
	str_len = ft_strlen(str);
	needle_len = ft_strlen(needle);
	if (str_len < needle_len || len < needle_len)
		return (0);
	while (*str && needle_len <= len)
	{
		if (ft_memcmp(str, needle, needle_len) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (0);
}
