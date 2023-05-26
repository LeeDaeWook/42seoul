/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:22:21 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 21:42:26 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_dollar_count(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '$')
			count++;
		i++;
	}
	return (count);
}

int	ft_validate_arg(char *arg)
{
	if (ft_strchr(arg, '\'') || ft_strchr(arg, '\"'))
		return (1);
	else if (ft_strchr(arg, '<') || ft_strchr(arg, '>'))
		return (0);
	return (1);
}

t_parse	*ft_is_redirect_arg(t_parse *p)
{
	if (p->next)
		return (p->next->next);
	else
		return (p->next);
}

int	ft_syntax_is_flag(t_rd *rd)
{
	t_rd	*p;

	p = rd;
	while (p)
	{
		if (!p->argument)
			return (1);
		p = p->next;
	}
	return (0);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}
