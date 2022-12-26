/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:08:21 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/11 16:42:29 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*ft_malloc(int size, char **strs, char *str_cat, char *sep)
{
	int	i;
	int	j;
	int	sep_len;
	int	strs_len;

	sep_len = 0;
	while (*(sep + sep_len))
		sep_len++;
	i = 0;
	strs_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			strs_len++;
			j++;
		}
		i++;
	}
	strs_len += sep_len * (size - 1);
	if (size <= 0) strs_len = 1;
	str_cat = (char*)malloc(sizeof(char) * strs_len);
	if (str_cat == 0)
		return (0);
	return 
		(str_cat);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_cat;
	int 		i;
	int		j;
	int		k;

	str_cat = ft_malloc(size, strs, str_cat, sep);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str_cat[k++] = strs[i][j++];
		j = 0;
		while (i <= (size - 1) && sep[j])
			str_cat[k++] = sep[j++];
		i++;
	}
	str_cat[k] = '\0';
	return (str_cat);
}

int main()
{
	char *str_join[] = {"hello","my", "name", "is", "lee"};
	char sep[10] = "**@@@";
	int	size = 5;
	printf("str = hello, my, name, is, lee\t size = %d, sep = %s\n", size, sep);
	printf("%s\n", ft_strjoin(size, str_join, sep));
}
