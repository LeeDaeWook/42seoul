/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_add_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:25:27 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 15:49:00 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_valid_data(char *str)
{
	if (ft_isdigit(*str))
		return (1);
	while (*str && *str != '=')
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (1);
		str++;
	}
	return (0);
}

void	ft_free_env(t_env *env)
{
	free(env->content);
	free(env->key);
	free(env->value);
	env->key = NULL;
	env->value = NULL;
	env->content = NULL;
	free(env);
}

void	ft_change_value(t_env **lst, t_env *new)
{
	free((*lst)->value);
	free((*lst)->content);
	(*lst)->value = ft_strdup(new->value);
	(*lst)->content = ft_strdup(new->content);
	ft_free_env(new);
}

void	env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*temp;

	temp = *lst;
	if (!(*lst) && new)
	{
		*lst = new;
		return ;
	}
	else if (!new)
		return ;
	while (*lst)
	{
		if (!ft_strcmp((*lst)->key, new->key))
		{
			if (ft_strchr(new->content, '='))
				ft_change_value(lst, new);
			*lst = temp;
			return ;
		}
		if (!(*lst)->next)
			break ;
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
	*lst = temp;
}

t_env	*env_lstnew(char *content)
{
	t_env	*new_node;
	char	*temp;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		ft_malloc_exit();
	temp = ft_strchr(content, '=');
	new_node->content = ft_strdup(content);
	new_node->key = ft_substr(content, 0, temp - content);
	new_node->value = ft_substr(content, temp - content + 1, \
	ft_strlen(content) - (temp - content));
	new_node->next = NULL;
	return (new_node);
}
