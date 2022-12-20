/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:16:06 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 21:27:55 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void*ptr, int c, size_t len)
{
	unsigned int	i;
	char		*char_ptr;

	i = 0;
	if (len > ft_strlen(ptr))
		return (0);
	char_ptr = (char *)ptr;
	while (i < len)
		char_ptr[i++] = (unsigned char)c;
	return (ptr);
}

/*
typedef struct s_flag
{
    int minus;
    int zero;
    int dot;
    int star;

}   t_flag;

#include <string.h>
#include <stdio.h>

int	main(void)
{
	t_flag flag1;
	t_flag flag2;

	memset((void*)&flag1, 0, sizeof(flag1));
	ft_memset((void*)&flag2, 0, sizeof(flag2) / 4);

	printf("%d %d %d %d\n", flag1.dot, flag1.minus, flag1.zero, flag1.star);
	printf("%d %d %d %d\n", flag2.dot, flag2.minus, flag2.zero, flag2.star);
	return (0);
}
*/
