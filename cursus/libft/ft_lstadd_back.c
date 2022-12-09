/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:34:06 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/30 13:34:13 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

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
