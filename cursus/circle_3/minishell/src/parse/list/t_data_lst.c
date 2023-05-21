/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:32:28 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 15:33:44 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_data_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*head;

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

void	t_data_lstclear(t_data **lst)
{
	t_data	*temp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		t_rd_lstclear(&(*lst)->rd);
		temp = (*lst)->next;
		t_data_lst_delone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	t_data_lst_delone(t_data *lst)
{
	if (!lst)
		return ;
	if (lst)
	{
		if (lst->content)
			free(lst->content);
		if (lst->argv)
			ft_double_free(lst->argv);
		if (lst->path)
			free(lst->path);
		lst->next = NULL;
		free(lst);
		lst = NULL;
	}
}

t_data	*ft_new_parsing_node(char *content)
{
	t_data	*new_parsing_node;

	new_parsing_node = (t_data *)malloc(sizeof(t_data));
	if (!new_parsing_node)
		ft_malloc_exit();
	ft_bzero(new_parsing_node, sizeof(t_data));
	new_parsing_node->content = content;
	return (new_parsing_node);
}

int	t_data_lstsize(t_data *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
