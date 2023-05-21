/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_parse_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:15:52 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 21:47:33 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse	*ft_make_parse_arg(t_parse *parse_node, char *str, int start, int i)
{
	t_parse	*new_parse_node;

	while (str[i])
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t' && \
				str[i] != '<' && str[i] != '>')
		{
			if (str[i] == '\'' || str[i] == '\"')
				i = ft_loop_quote(str, i);
			i++;
		}
		if (start == i && (str[i] == '<' || str[i] == '>'))
			i = ft_loop_redirection(str, i);
		if (i - start)
		{
			new_parse_node = t_parse_lstnew(ft_substr(str, start, i - start));
			if (!new_parse_node)
				return (parse_node);
			t_parse_lstadd_back(&parse_node, new_parse_node);
		}
		start = ft_loop_start(str, i);
		i = start;
	}
	return (parse_node);
}

int	ft_loop_start(char *str, int i)
{
	while (str[i] && ft_is_space(str[i]))
		i++;
	return (i);
}

int	ft_loop_redirection(char *str, int i)
{
	i += 1;
	while (str[i] && (str[i] == '<' || str[i] == '>'))
		i++;
	return (i);
}

int	ft_loop_quote(char *str, int i)
{
	char	quote_type;

	quote_type = '\'';
	if (str[i] == '\"')
		quote_type = '\"';
	i += 1;
	while (str[i] && str[i] != quote_type)
		i++;
	return (i);
}

char	**ft_make_argv(t_parse *parse_node, int lst_size)
{
	t_parse	*p;
	char	**new_argv;

	if (!lst_size)
		return (NULL);
	new_argv = (char **)malloc(sizeof(char *) * (lst_size + 1));
	if (!new_argv)
		ft_malloc_exit();
	p = parse_node;
	lst_size = 0;
	while (p)
	{
		if (p->type)
			p = ft_is_redirect_arg(p);
		else
		{
			new_argv[lst_size++] = ft_strdup(p->arg);
			p = p->next;
		}
	}
	new_argv[lst_size] = NULL;
	return (new_argv);
}
