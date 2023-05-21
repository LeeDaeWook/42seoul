/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:37:33 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/01 16:21:47 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	chr;

	if (!s)
		return (0);
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

void	remove_node(t_n **head, t_n **cur, t_n **before)
{
	t_n	*temp;

	temp = (*cur);
	if ((*cur)->backup)
	{
		free((*cur)->backup);
		(*cur)->backup = 0;
	}
	if (*head == *cur)
	{
		*cur = (*cur)->next;
		*head = *cur;
	}
	else
		(*before)->next = (*cur)->next;
	free(temp);
}
