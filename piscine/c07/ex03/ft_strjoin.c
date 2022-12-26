/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:19:06 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/12 18:29:59 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_malloc(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		sep_len;
	int		strs_len;
	char	*str_cat;

	sep_len = 0;
	while (*(sep + sep_len))
		sep_len++;
	i = 0;
	strs_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++] != '\0')
			strs_len++;
		i++;
	}
	strs_len += sep_len * (size - 1);
	if (size <= 0)
		strs_len = 1;
	str_cat = (char *)malloc(sizeof(char) * (strs_len + 1));
	if (str_cat == 0)
		return (0);
	return (str_cat);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_cat;
	int		i;
	int		j;
	int		k;

	str_cat = ft_malloc(size, strs, sep);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str_cat[k++] = strs[i][j++];
		j = 0;
		while (i < (size - 1) && sep[j])
			str_cat[k++] = sep[j++];
		i++;
	}
	str_cat[k] = '\0';
	return (str_cat);
}
