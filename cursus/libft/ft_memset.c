/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:16:06 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/22 17:52:19 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void*ptr, int c, size_t len)
{
	unsigned int	i;
	char			*char_ptr;

	i = 0;
	char_ptr = (char *)ptr;
	while (i < len)
		char_ptr[i++] = (unsigned char)c;
	return (ptr);
}

