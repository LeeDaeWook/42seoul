/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rd_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:33:36 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/04 02:21:18 by kyeonkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_rd_lst_delone(t_rd *lst)
{
	if (!lst)
		return ;
	if (lst)
	{
		if (lst->argument)
			free(lst->argument);
		lst->next = NULL;
		free(lst);
		lst = NULL;
	}
}

void	t_rd_lstclear(t_rd **lst)
{
	t_rd	*temp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		t_rd_lst_delone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	t_rd_lstadd_back(t_rd **lst, t_rd *new)
{
	t_rd	*head;

	if (!(*lst))
		*lst = new;
	else
	{
		head = *lst;
		while (head->next)
			head = head->next;
		head->next = new;
	}
}

t_rd	*t_rd_lstnew(t_parse *p)
{
	t_rd	*new_rd_node;

	new_rd_node = (t_rd *)malloc(sizeof(t_rd));
	if (!new_rd_node)
		ft_malloc_exit();
	ft_bzero(new_rd_node, sizeof(t_rd));
	new_rd_node->type = p->type;
	if (p->next)
	{
		if (ft_strchr(p->next->arg, '\'') || ft_strchr(p->next->arg, '\"'))
		{
			new_rd_node->is_quote = 1;
			p->next->arg = ft_remove_quote(p->next->arg);
		}
		new_rd_node->argument = ft_strdup(p->next->arg);
	}
	return (new_rd_node);
}
