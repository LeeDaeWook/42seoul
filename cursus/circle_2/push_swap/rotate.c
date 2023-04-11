/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:24:14 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:31:40 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_deque *stack, int idx)
{
	t_node	*original_top;
	t_node	*original_bottom;

	original_top = stack->top;
	original_bottom = stack->bottom;
	original_bottom->next = original_top;
	stack->top = original_top->next;
	stack->top->pre = NULL;
	stack->bottom = original_top;
	stack->bottom->pre = original_bottom;
	stack->bottom->next = NULL;
	if (idx != RR && idx != RRR)
		print_instructions(idx, NULL);
}
