/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:23:29 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 12:24:09 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *stack)
{
	t_node	*second_node;

	if (stack->size < 2)
	{
		ft_printf("at least 2 arguments needed\n");
		exit(EXIT_FAILURE);
	}	
	second_node = stack->top->next;
	stack->top->next = second_node->next;
	second_node->next->pre = stack->top;
	second_node->next = stack->top;
	stack->top->pre = second_node;
	stack->top = second_node;
	stack->top->pre = NULL;
	print_instructions(SWAP, stack);
}
