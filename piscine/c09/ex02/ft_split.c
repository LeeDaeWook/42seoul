/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:58:45 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/13 16:58:50 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	not_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	if (c == '\0')
		return (0);
	return (1);
}

int	word_count(char*str, char*charset)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (str[i] != '\0')
	{
		if ((not_charset(str[i], charset) && !not_charset(str[i + 1], charset)))
			wordcount++;
		i++;
	}
	return (wordcount);
}

void	ft_strcpy(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (not_charset(src[i], charset) == 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	split(char **result, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (not_charset(str[i], charset) == 0)
			i++;
		else
		{
			j = 0;
			while (not_charset(str[i + j], charset) == 1)
				j++;
			result[word] = (char *)malloc(sizeof(char) * (j + 1));
			ft_strcpy(result[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word;

	word = word_count(str, charset);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	result[word] = 0;
	split(result, str, charset);
	return (result);
}
