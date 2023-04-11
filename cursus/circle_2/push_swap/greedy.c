/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:08:17 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:32:02 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**greedy(t_deque *from, t_deque *to)
{
	t_node	*temp;
	int		**count;
	int		i;

	temp = from->top;
	count = (int **)malloc(sizeof(int *) * from->size);
	i = 0;
	while (temp)
	{
		count[i] = (int *)malloc(sizeof(int) * 7);
		fill_count(temp, from, to, count[i]);
		temp = temp->next;
		i++;
	}
	return (count);
}

void	execute_instructions(int *count, t_deque *from, t_deque *to)
{
	if (count[RA] && from->stack == STACK_A)
		recursion_r_rr(count, from, RA);
	else if (count[RA] && to->stack == STACK_A)
		recursion_r_rr(count, to, RA);
	if (count[RB] && from->stack == STACK_B)
		recursion_r_rr(count, from, RB);
	else if (count[RB] && to->stack == STACK_B)
		recursion_r_rr(count, to, RB);
	if (count[RRA] && from->stack == STACK_A)
		recursion_r_rr(count, from, RRA);
	else if (count[RRA] && to->stack == STACK_A)
		recursion_r_rr(count, to, RRA);
	if (count[RRB] && from->stack == STACK_B)
		recursion_r_rr(count, from, RRB);
	else if (count[RRB] && to->stack == STACK_B)
		recursion_r_rr(count, to, RRB);
	if (count[RR])
		recursion_rr_rrr(count, from, to, RR);
	else if (count[RRR])
		recursion_rr_rrr(count, from, to, RRR);
	push(to, from);
}

void	recursion_r_rr(int *count, t_deque *stack, int idx)
{
	if (!count[idx])
		return ;
	if (idx == RA || idx == RB)
		rotate(stack, idx);
	else if (idx == RRA || idx == RRB)
		reverse_rotate(stack, idx);
	count[idx] -= 1;
	if (count[idx] > 0)
		recursion_r_rr(count, stack, idx);
}

void	recursion_rr_rrr(int *count, t_deque *from, t_deque *to, int idx)
{
	if (idx == RR)
	{
		rotate(from, idx);
		rotate(to, idx);
	}
	else if (idx == RRR)
	{
		reverse_rotate(from, idx);
		reverse_rotate(to, idx);
	}
	print_instructions(idx, NULL);
	count[idx] -= 1;
	if (count[idx] > 0)
		recursion_rr_rrr(count, from, to, idx);
}
