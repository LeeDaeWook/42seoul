/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_temp_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:35:20 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 15:31:16 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_lstadd_back(t_temp **lst, t_temp *new)
{
	t_temp	*temp;

	temp = *lst;
	if (!(*lst) && new)
	{
		*lst = new;
		return ;
	}
	else if (!new)
		return ;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = temp;
}

void	t_temp_lstdelone(t_temp *lst)
{
	if (!lst)
		return ;
	if (lst)
	{
		if (lst->str)
		{
			free(lst->str);
			lst->str = NULL;
		}
		lst->next = NULL;
		free(lst);
		lst = NULL;
	}
}

void	t_temp_lst_clear(t_temp **lst)
{
	t_temp	*temp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		t_temp_lstdelone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

t_temp	*ft_quote_add_node(char *str, int is_quote)
{
	t_temp	*node;

	node = (t_temp *)malloc(sizeof(t_temp));
	if (!node)
		ft_malloc_exit();
	node->str = str;
	node->is_quote = is_quote;
	node->next = NULL;
	return (node);
}

char	*ft_create_new_argv(t_temp *head)
{
	char	*new_argv;
	t_temp	*p;
	char	*temp;

	p = head;
	new_argv = NULL;
	while (p)
	{
		if (!new_argv)
			new_argv = ft_strdup(p->str);
		else
		{
			temp = new_argv;
			new_argv = ft_strjoin(new_argv, p->str);
			free(temp);
		}
		p = p->next;
	}
	return (new_argv);
}
