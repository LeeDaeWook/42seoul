/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:42:00 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/01 17:35:10 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while ((i + 1) < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if ((i + 1) <= size)
		dest[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
