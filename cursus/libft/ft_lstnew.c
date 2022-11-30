/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:59:37 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/30 12:55:41 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list*)malloc(sizeof(t_list) * 1);
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}

/*
#include <stdio.h>

int main(void)
{
	t_list	*new;
	int	d;

	d = 10000;
	new = ft_lstnew(&d);
	printf("%d\n", *(int*)ft_lstnew(&d)->content);

	return (0);
}
*/
