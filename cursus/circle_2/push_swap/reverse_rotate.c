/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:24:45 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 12:30:11 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_deque *stack, int idx)
{
	t_node	*original_top;
	t_node	*original_bottom;

	original_top = stack->top;
	original_bottom = stack->bottom;
	original_top->pre = original_bottom;
	original_bottom->next = original_top;
	stack->bottom = original_bottom->pre;
	stack->bottom->next = NULL;
	stack->top = original_bottom;
	stack->top->pre = NULL;
	if (idx != RR && idx != RRR)
		print_instructions(idx, NULL);
}
