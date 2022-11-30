/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:25:02 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/22 21:25:07 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

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

void	ft_strcpy(char *dest, char const *src, char c)
{
	int	i;

	i = 0;
	while (not_charset(src[i], c) == 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	split(char **result, char const *s, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
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
			ft_strcpy(result[word], s + i, c);
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
	result[word] = 0;
	split(result, s, c);
	return (result);
}

/*
#include <stdio.h>

int main(void)
{
	char s[] = "abco123o123456o::dddd";
	int	i = 0;
	char	**result;

	result = ft_split(s, 'o');
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}

	return (0);
}
*/
