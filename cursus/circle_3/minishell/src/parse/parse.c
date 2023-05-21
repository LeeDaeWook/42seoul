/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:54:30 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/04 13:13:08 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*ft_parse(t_data *p_node, t_env *envp)
{
	t_parse	*parse_node;

	parse_node = ft_make_parse_node(p_node->content);
	if (parse_node && parse_node->is_syntax)
	{
		t_data_lstclear(&p_node);
		t_parse_lstclear(&parse_node);
		return (NULL);
	}
	p_node = ft_process_redirection(p_node, parse_node);
	parse_node = ft_quota_env_convert(parse_node, envp);
	p_node->argv = ft_make_argv(parse_node, t_parse_lstsize(parse_node));
	t_parse_lstclear(&parse_node);
	return (p_node);
}

t_parse	*ft_make_parse_node(char *str)
{
	t_parse	*parse_node;

	parse_node = NULL;
	if (!str)
		return (NULL);
	parse_node = ft_make_parse_arg(parse_node, str, 0, 0);
	parse_node = ft_insert_parse_type(parse_node);
	return (parse_node);
}

t_parse	*ft_quota_env_convert(t_parse *parse_node, t_env *envp)
{
	t_parse	*p;
	t_temp	*head;

	head = NULL;
	p = parse_node;
	while (p)
	{
		head = ft_divied_quote(p->arg, head);
		head = ft_find_env(head, envp);
		free(p->arg);
		p->arg = ft_create_new_argv(head);
		t_temp_lst_clear(&head);
		p = p->next;
	}
	return (parse_node);
}

t_data	*ft_process_redirection(t_data *new_parsing_node, t_parse *parse_node)
{
	t_parse	*p;
	t_rd	*new_rd_node;

	p = parse_node;
	while (p)
	{
		if (p->type)
		{
			if (p->type == HEREDOC)
				new_parsing_node->is_heredoc = 1;
			new_rd_node = t_rd_lstnew(p);
			t_rd_lstadd_back(&new_parsing_node->rd, new_rd_node);
			if (p->next)
				p = p->next->next;
			else
				p = p->next;
		}
		else
			p = p->next;
	}
	return (new_parsing_node);
}

t_data	*ft_parsing_pipe(char *line, t_data *p_node, int start)
{
	t_data	*new_node;
	int		i;

	i = 0;
	while (line[i])
	{
		i = ft_loop_start(line, i);
		start = i;
		while (line[i] && line [i] != '|')
		{
			if (line[i] == '\'' || line[i] == '\"')
				i = ft_loop_quote(line, i);
			i++;
		}
		if (i - start || line [i] == '|')
		{
			new_node = ft_new_parsing_node(ft_substr(line, start, i - start));
			if (!new_node)
				return (NULL);
			t_data_lstadd_back(&p_node, new_node);
		}
		if (line[i])
			i++;
	}
	return (p_node);
}
