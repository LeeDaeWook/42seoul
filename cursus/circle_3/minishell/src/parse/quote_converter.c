/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:18:36 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/04 13:09:05 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_temp	*ft_divied_quote(char *str, t_temp *head)
{
	int		flag[2];
	size_t	size;
	int		is_quote;

	ft_bzero((void *)flag, sizeof(int) * 2);
	while (*str)
	{
		if (!flag[SINGLE] && !flag[DOUBLE] && *str != '\'' && *str != '\"')
		{
			size = ft_count_size(str, flag);
			quote_lstadd_back(&head, \
			ft_quote_add_node(ft_trim_env(str, 0, size), NONE));
			str += size;
		}
		if (*str == '\'' || *str == '\"')
		{
			quote_flag(*str, flag);
			is_quote = ft_is_quote(*str++);
			size = ft_count_size(str, flag);
			quote_lstadd_back(&head, \
			ft_quote_add_node(ft_trim_env(str, 0, size), is_quote));
			str += size + 1;
		}
	}
	return (head);
}

size_t	ft_count_size(char *str, int *flag)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		if ((flag[SINGLE] && *str == '\'') || (flag[DOUBLE] && *str == '\"'))
		{
			quote_flag(*str, flag);
			break ;
		}
		if (!flag[SINGLE] && !flag[DOUBLE] && (*str == '\'' || *str == '\"'))
			break ;
		str++;
		size++;
	}
	return (size);
}

char	*ft_trim_env(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (!len || ft_strlen((char *)s) <= start)
		str = (char *)malloc(sizeof(char));
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) - start + 1));
	if (!str)
		ft_malloc_exit();
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_is_quote(char c)
{
	int	is_quote;

	if (c == '\'')
		is_quote = SINGLE;
	else
		is_quote = DOUBLE;
	return (is_quote);
}

char	*ft_remove_quote(char *str)
{
	t_temp	*head;

	head = NULL;
	head = ft_divied_quote(str, head);
	free(str);
	str = ft_create_new_argv(head);
	t_temp_lst_clear(&head);
	return (str);
}
