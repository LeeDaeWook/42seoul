/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:12:37 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:37:29 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_location_b(t_node *node, t_deque *stack)
{
	int		idx;
	t_node	*temp;

	idx = 1;
	temp = stack->top;
	if (node->num > stack->max->num || node->num < stack->min->num)
		idx = find_idx(stack->max, stack);
	else if (stack->stack == STACK_B)
	{
		while (idx < stack->size)
		{
			if (node->num < temp->num && node->num > temp->next->num)
				break ;
			idx++;
			temp = temp->next;
		}
	}
	return (idx);
}

int	find_location_a(t_node *node, t_deque *stack)
{
	int		idx;
	t_node	*temp;

	idx = 1;
	temp = stack->top;
	if (node->num < stack->min->num)
		idx = find_idx(stack->min, stack);
	else if (node->num > stack->max->num)
		idx = find_idx(stack->max, stack) + 1;
	else
	{
		while (idx < stack->size)
		{
			if (node->num > temp->num && node->num < temp->next->num)
				return (idx);
			idx++;
			temp = temp->next;
		}
		idx = 0;
	}
	return (idx);
}

int	find_idx(t_node *node, t_deque *stack)
{
	t_node	*temp;
	int		idx;

	temp = stack->top;
	idx = 0;
	while (node->num != temp->num)
	{
		idx++;
		temp = temp->next;
	}
	return (idx);
}

int	find_min_instructions(int **count, int size)
{
	int	i;
	int	min;
	int	min_idx;

	i = 0;
	min = INTEGER_MAX;
	while (i < size)
	{
		if (count[i][TOTAL_IDX] < min)
		{
			min = count[i][TOTAL_IDX];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

t_node	*find_min_node(t_deque *stack)
{
	t_node	*temp;
	t_node	*node;
	int		min_num;

	temp = stack->top;
	min_num = INTEGER_MAX;
	while (temp)
	{
		if (temp->num < min_num)
		{
			min_num = temp->num;
			node = temp;
		}
		temp = temp->next;
	}
	return (node);
}
