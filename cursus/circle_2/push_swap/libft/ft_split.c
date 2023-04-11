/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:25:02 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:39:18 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	not_charset(char c, char charset)
{
	if (c == charset)
		return (0);
	if (c == '\0')
		return (0);
	return (1);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		if ((not_charset(s[i], c) && !not_charset(s[i + 1], c)))
			wordcount++;
		i++;
	}
	return (wordcount);
}

void	ft_memfree(char **result, int word)
{
	while (word >= 0)
	{
		free(result[word]);
		result[word] = 0;
		word--;
	}
}

void	excute_ft_split(char **result, char const *s, char c, int i)
{
	int	j;
	int	word;

	word = 0;
	while (s[i] != '\0')
	{
		if (not_charset(s[i], c) == 0)
			i++;
		else
		{
			j = 0;
			while (not_charset(s[i + j], c) == 1)
				j++;
			result[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!result[word])
			{
				ft_memfree(result, --word);
				return ;
			}
			ft_strlcpy(result[word], s + i, j + 1);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word;

	word = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	if (!result)
		return (0);
	result[word] = 0;
	excute_ft_split(result, s, c, 0);
	return (result);
}
