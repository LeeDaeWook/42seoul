/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_parse_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:17:43 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 22:45:58 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse	*ft_insert_parse_type(t_parse *parse_node)
{
	t_parse	*p;
	int		type;

	p = parse_node;
	while (p)
	{
		type = ft_get_parse_node_type(p->arg);
		p->type = type;
		if (!type && !ft_validate_arg(p->arg))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_defined_error("syntax error near unexpected token ", \
				ft_make_err_arg(p->arg));
			g_exit_state = 258;
			parse_node->is_syntax = 1;
			return (parse_node);
		}
		p = p->next;
	}
	return (parse_node);
}

int	ft_get_parse_node_type(char *str)
{
	if (!ft_strcmp(str, "<"))
		return (t_IN);
	else if (!ft_strcmp(str, ">"))
		return (t_OUT);
	else if (!ft_strcmp(str, ">>"))
		return (t_APPEND);
	else if (!ft_strcmp(str, "<<"))
		return (t_HEREDOC);
	else
		return (CMD);
}
