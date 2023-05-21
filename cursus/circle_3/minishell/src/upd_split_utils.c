/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_split_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:58:45 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/03/31 16:01:34 by kyeonkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	not_charset(char c, char charset)
{
	if (c == charset)
		return (0);
	if (c == '\0')
		return (0);
	return (1);
}

void	quote_flag(char quote, int *flag)
{
	if (!flag[SINGLE] && quote == '\"' && !flag[DOUBLE])
		flag[DOUBLE] = 1;
	else if (!flag[SINGLE] && quote == '\"' && flag[DOUBLE])
		flag[DOUBLE] = 0;
	else if (!flag[DOUBLE] && quote == '\'' && !flag[SINGLE])
		flag[SINGLE] = 1;
	else if (!flag[DOUBLE] && quote == '\'' && flag[SINGLE])
		flag[SINGLE] = 0;
}

int	word_count(char const *s, char c)
{
	int	i;
	int	wordcount;
	int	flag[2];

	if (!s)
		return (0);
	i = 0;
	wordcount = 0;
	ft_bzero(flag, sizeof(int) * 2);
	while (s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '\"')
			quote_flag(s[i], flag);
		if (!flag[0] && !flag[1] && (not_charset(s[i], c) && \
				!not_charset(s[i + 1], c)))
			wordcount++;
		i++;
	}
	if (flag[0] || flag[1])
		wordcount++;
	return (wordcount);
}

void	ft_memfree(char **result, int word)
{
	while (word >= 0)
	{
		free(result[word]);
		result[word] = NULL;
		word--;
	}
}

int	ft_count_str_in_quote(char const *s, char c, int flag[2], int j)
{
	while (s[j] && (flag[0] || flag[1] || not_charset(s[j], c)))
	{
		if (s[j] == '\'' || s[j] == '\"')
			quote_flag(s[j], flag);
		j++;
	}
	return (j);
}
