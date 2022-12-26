/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:51:34 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/11 22:11:37 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	word_count(char*str, char*charset)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] != charset[0])
			wordcount++;
		else if (str[i - 1] == charset[0] && str[i] != charset[0])
			wordcount++;
		i++;
	}
	return (wordcount + 1);
}

int	str_len(char *str, char *charset, int k)
{
	int	strlen;

	strlen = 0;
	while (*(str + k) != charset[0] && *(str + k) != '\0')
	{
		strlen++;
		k++;
	}
	return (strlen + 1);
}

int	sep_len(char*charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**result_str;
	int		strlen;

	i = 0;
	k = 0;
	result_str = (char **)malloc(sizeof(char *) * word_count(str, charset));
	if (result_str == 0)
		return (0);
	while (i + 1 < word_count(str, charset))
	{	
		result_str[i] = (char *)malloc(sizeof(char) * str_len(str, charset, k));
		strlen = str_len(str, charset, k);
		j = 0;
		while (j + 1 < strlen)
			result_str[i][j++] = str[k++];
		result_str[i][j] = '\0';
		k += sep_len(charset);
		i++;
	}
	result_str[i] = 0;
	return (result_str);
}
