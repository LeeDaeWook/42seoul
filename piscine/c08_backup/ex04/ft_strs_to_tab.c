/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:37:22 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/10 21:08:50 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

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

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	t_stock_str *ptr;
	
	ptr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (ptr == 0)
		return (NULL);;
	while (i < ac)
	{
		ptr[i].size = ft_strlen(av[i]);
		ptr[i].str = av[i];
		ptr[i].copy = ft_strdup(av[i]);
		i++;
	}
	ptr[i].str = 0;

	return (ptr);
}
