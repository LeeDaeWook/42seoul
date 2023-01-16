/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:37:33 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/16 10:37:46 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	chr;

	str = (char *)s;
	chr = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == chr)
			return (str);
		str++;
	}
	if (*str == '\0' && chr == '\0')
		return (str);
	return (0);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*dest;

	src_len = ft_strlen(src);
	dest = malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (0);
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	dest = dest - src_len;
	return (dest);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	free(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}