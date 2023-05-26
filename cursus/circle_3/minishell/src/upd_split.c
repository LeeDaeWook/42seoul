/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:25:02 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/31 17:25:51 by kyeonkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	excute_ft_split(char **result, char const *s, char c, int i)
{
	int		j;
	int		word;
	int		flag[2];

	word = 0;
	ft_bzero(flag, sizeof(int) * 2);
	while (s[i] != '\0')
	{
		if (!not_charset(s[i], c))
			i++;
		else
		{
			j = ft_count_str_in_quote(s, c, flag, i);
			result[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!result[word])
				ft_malloc_exit();
			ft_strlcpy(result[word++], s + i, j - i + 1);
			i = j;
		}
	}
}

char	**upd_split(char const *s, char c)
{
	char	**result;
	int		word;

	word = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	if (!result)
		ft_malloc_exit();
	result[word] = NULL;
	if (!word)
		return (result);
	excute_ft_split(result, s, c, 0);
	return (result);
}
