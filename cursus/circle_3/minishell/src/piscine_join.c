/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:19:06 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/31 16:06:28 by kyeonkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*upd_malloc(int size, char **strs)
{
	int		i;
	int		j;
	int		strs_len;
	char	*str_cat;

	i = 0;
	strs_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++] != '\0')
			strs_len++;
		i++;
	}
	if (size <= 0)
		strs_len = 1;
	str_cat = (char *)malloc(sizeof(char) * (strs_len + 1));
	if (!str_cat)
		ft_malloc_exit();
	return (str_cat);
}

char	*upd_strjoin(int size, char **strs)
{
	char	*str_cat;
	int		i;
	int		j;
	int		k;

	str_cat = upd_malloc(size, strs);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str_cat[k++] = strs[i][j++];
		i++;
	}
	str_cat[k] = '\0';
	return (str_cat);
}
