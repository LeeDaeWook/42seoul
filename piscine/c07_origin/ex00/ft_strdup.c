/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:51:37 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/10 20:54:35 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*cp_src;

	src_len = 0;
	while (*(src + src_len))
		src_len++;
	cp_src = malloc(sizeof(char*) * (src_len + 1));
	if (!cp_src)
		return (NULL);
	while (*src)
		*cp_src++ = *src++;
	*cp_src = '\0';
	cp_src = cp_src - src_len;
	return (cp_src);
}
