/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:18:53 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:40:45 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_checker(t_deque *to, t_deque *from)
{
	t_node	*temp;

	if (from->size == 0)
		return ;
	temp = from->top->next;
	from->top->next = to->top;
	to->top = from->top;
	to->top->pre = NULL;
	from->top = temp;
	if (from->top)
		from->top->pre = NULL;
	if (to->top->next)
		to->top->next->pre = to->top;
	if (!to->size)
		to->bottom = to->top;
	(to->size)++;
	(from->size)--;
	if (!(from->size))
		ft_bzero((void *)from, sizeof(t_deque));
	compare_max_min_checker(to);
}

void	compare_max_min_checker(t_deque *to)
{
	if (!to->max && !to->min)
	{
		to->max = to->top;
		to->min = to->top;
	}
	else if (to->max && to->top->num > to->max->num)
		to->max = to->top;
	else if (to->min && to->top->num < to->min->num)
		to->min = to->top;
}

void	swap_checker(t_deque *deque)
{
	t_node	*second_node;

	if (deque->size < 2)
	{
		ft_printf("at least 2 arguments needed\n");
		exit(EXIT_FAILURE);
	}
	second_node = deque->top->next;
	deque->top->next = second_node->next;
	second_node->next->pre = deque->top;
	second_node->next = deque->top;
	deque->top->pre = second_node;
	deque->top = second_node;
	deque->top->pre = NULL;
}

void	rotate_checker(t_deque *deque)
{
	t_node	*original_top;
	t_node	*original_bottom;

	original_top = deque->top;
	original_bottom = deque->bottom;
	original_bottom->next = original_top;
	deque->top = original_top->next;
	deque->top->pre = NULL;
	deque->bottom = original_top;
	deque->bottom->pre = original_bottom;
	deque->bottom->next = NULL;
}

void	reverse_rotate_checker(t_deque *deque)
{
	t_node	*original_top;
	t_node	*original_bottom;

	original_top = deque->top;
	original_bottom = deque->bottom;
	original_top->pre = original_bottom;
	original_bottom->next = original_top;
	deque->bottom = original_bottom->pre;
	deque->bottom->next = NULL;
	deque->top = original_bottom;
	deque->top->pre = NULL;
}
