/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:34:41 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 20:04:17 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	unsigned int	i;
	int		diff;

	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n )
	{
		diff = (new_s1[i] - new_s2[i]);
		if (new_s1[i] > new_s2[i])
			return (diff);
		else if (new_s1[i] < new_s2[i])
			return (diff);
		else if (new_s1[i] == new_s2[i])
			i++;
	}
	return (0);
}
