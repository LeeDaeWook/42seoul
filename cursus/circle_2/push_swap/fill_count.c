/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:15:50 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:36:42 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_count(t_node *node, t_deque *from, t_deque *to, int *count)
{
	int	idx;

	ft_bzero((void *)count, sizeof(int) * 7);
	idx = find_idx(node, from);
	if (idx <= (from->size / 2))
		r_rr_from(node, from, count, ROTATE);
	else if (idx > (from->size / 2))
		r_rr_from(node, from, count, REVERSE_ROTATE);
	idx = find_location_b(node, to);
	if (idx <= (to->size / 2))
		r_rr_to(idx, to, count, ROTATE);
	else if (idx > (to->size / 2))
		r_rr_to(idx, to, count, REVERSE_ROTATE);
	rr_rrr(count);
	idx = 0;
	while (idx < TOTAL_IDX)
	{
		count[TOTAL_IDX] += count[idx];
		idx++;
	}
}

void	r_rr_from(t_node *node, t_deque *stack, int *count, int flag)
{
	t_node	*temp;

	temp = node;
	while (temp && temp->num != stack->top->num)
	{
		if (flag == ROTATE)
		{
			if (stack->stack == STACK_A)
				count[RA] += 1;
			else if (stack->stack == STACK_B)
				count[RB] += 1;
			temp = temp->pre;
		}
		else if (flag == REVERSE_ROTATE)
		{
			if (stack->stack == STACK_A)
				count[RRA] += 1;
			else if (stack->stack == STACK_B)
				count[RRB] += 1;
			temp = temp->next;
		}
	}
}

void	r_rr_to(int idx, t_deque *stack, int *count, int flag)
{
	while ((flag == ROTATE && idx > 0) || \
			(flag == REVERSE_ROTATE && idx < stack->size))
	{
		if (flag == ROTATE)
		{
			if (stack->stack == STACK_A)
				count[RA] += 1;
			else if (stack->stack == STACK_B)
				count[RB] += 1;
			idx--;
		}
		else if (flag == REVERSE_ROTATE)
		{
			if (stack->stack == STACK_A)
				count[RRA] += 1;
			else if (stack->stack == STACK_B)
				count[RRB] += 1;
			idx++;
		}
	}
}

void	rr_rrr(int *count)
{
	if (count[RA] >= count[RB])
		count[RR] = count[RB];
	else if (count[RA] < count[RB])
		count[RR] = count[RA];
	count[RA] -= count[RR];
	count[RB] -= count[RR];
	if (count[RRA] >= count[RRB])
		count[RRR] = count[RRB];
	else if (count[RRA] < count[RRB])
		count[RRR] = count[RRA];
	count[RRA] -= count[RRR];
	count[RRB] -= count[RRR];
}
