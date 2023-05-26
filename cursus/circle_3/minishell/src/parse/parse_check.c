/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:18:35 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/04 20:38:17 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_env_dollar(char *ft_env)
{
	int		i;

	i = 0;
	while (ft_env[i])
	{
		if (ft_env[i] == '$')
		{
			if (!ft_env[i + 1])
				return (1);
		}
		i++;
	}
	return (0);
}

t_data	*ft_print_syntax(t_data *p_data, char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("syntax error near unexpected token \'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\'\n", 2);
	t_data_lstclear(&p_data);
	return (NULL);
}

t_data	*ft_check_syntax(t_data *p_data)
{
	t_data	*p;
	int		flag;

	if (g_exit_state == 258)
	flag = 0;
	p = p_data;
	while (p)
	{
		flag = ft_syntax_is_flag(p->rd);
		if (!p->next && !p->argv && !p->rd)
			return (ft_print_syntax(p_data, "|"));
		if (!p->argv && !p->rd)
			return (ft_print_syntax(p_data, "|"));
		if (p->next && flag == 1 && p->rd)
			return (ft_print_syntax(p_data, "|"));
		if (flag == 1 && p->rd)
			return (ft_print_syntax(p_data, "newline"));
		p = p->next;
	}
	return (p_data);
}

t_data	*ft_check_pipe(char *line, t_data *p_node)
{
	t_data	*new_node;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			i++;
			while (line[i] && ft_is_space(line[i]))
				i++;
			if (!line[i])
			{
				new_node = ft_new_parsing_node(NULL);
				if (!new_node)
					return (NULL);
				t_data_lstadd_back(&p_node, new_node);
			}
		}
		if (line[i])
			i++;
	}
	return (p_node);
}

int	ft_check_quote(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			i = ft_loop_quote(line, i);
			if (!line[i])
			{
				ft_putstr_fd("bash: syntax error near unexpected token\n", 2);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
