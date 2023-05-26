/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:29:17 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 15:33:24 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_env_lst_delone(t_env *lst)
{
	if (!lst)
		return ;
	if (lst)
	{
		if (lst->content)
			free(lst->content);
		if (lst->key)
			free(lst->key);
		if (lst->value)
			free(lst->value);
		lst->next = NULL;
		free(lst);
		lst = NULL;
	}
}

void	t_env_lstclear(t_env **lst)
{
	t_env	*temp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		t_env_lst_delone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

int	t_env_lstsize(t_env *lst)
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
