/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:34:20 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 20:25:30 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_parse_lst_delone(t_parse *lst)
{
	if (!lst)
		return ;
	if (lst)
	{
		if (lst->arg)
		{
			free(lst->arg);
			lst->arg = NULL;
		}
		lst->next = NULL;
		free(lst);
		lst = NULL;
	}
}

void	t_parse_lstclear(t_parse **lst)
{
	t_parse	*temp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		t_parse_lst_delone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

int	t_parse_lstsize(t_parse *parse_node)
{
	t_parse	*p;
	int		size;

	p = parse_node;
	size = 0;
	while (p)
	{
		if (p->type)
		{
			if (p->next)
				p = p->next->next;
			else
				p = p->next;
		}
		else
		{
			size++;
			p = p->next;
		}
	}
	return (size);
}

void	t_parse_lstadd_back(t_parse **lst, t_parse *new)
{
	t_parse	*head;

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

t_parse	*t_parse_lstnew(char *arg)
{
	t_parse	*new_parse_node;

	new_parse_node = (t_parse *)malloc(sizeof(t_parse));
	if (!new_parse_node)
		ft_malloc_exit();
	ft_bzero(new_parse_node, sizeof(t_parse));
	new_parse_node->arg = arg;
	return (new_parse_node);
}
