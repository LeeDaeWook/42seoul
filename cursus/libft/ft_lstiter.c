/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:44 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/30 13:32:55 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
	lst = temp;
}
/*
#include <stdio.h>

void	ft_print(void *content)
{
	printf("%d\n", *(int*)content);
}

int main(void)
{
	t_list	*head;
	t_list	node1;
	t_list	node2;
	int	con1;
	int	con2;

	head = &node1;

	con1 = 123;
	node1.content = &con1;
	node1.next = &node2;
	
	con2 = 456;
	node2.content = &con2;
	node2.next = 0;
	ft_lstiter(head, ft_print);

	return (0);
}
*/
