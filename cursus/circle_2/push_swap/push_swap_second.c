/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:30:17 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 12:34:09 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_second(t_deque *from, t_deque *to)
{
	int	*count;
	int	idx;

	while (from->size > 0)
	{
		count = (int *)malloc(sizeof(int) * 7);
		ft_bzero((void *)count, sizeof(int) * 7);
		idx = find_location_a(from->top, to);
		if (idx <= (to->size / 2))
		{
			count[RA] = idx;
			recursion_r_rr(count, to, RA);
		}
		else if (idx > (to->size / 2))
		{
			count[RRA] = to->size - idx;
			recursion_r_rr(count, to, RRA);
		}
		push(to, from);
		free(count);
	}
}
