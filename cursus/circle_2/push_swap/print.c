/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:04:55 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:05:51 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructions(int flag, t_deque *stack)
{
	if (stack && flag == SWAP && stack->stack == STACK_A)
		ft_printf("sa\n");
	else if (stack && flag == SWAP && stack->stack == STACK_B)
		ft_printf("sb\n");
	else if (stack && flag == PUSH && stack->stack == STACK_A)
		ft_printf("pa\n");
	else if (stack && flag == PUSH && stack->stack == STACK_B)
		ft_printf("pb\n");
	else if (!stack && flag == RA)
		ft_printf("ra\n");
	else if (!stack && flag == RB)
		ft_printf("rb\n");
	else if (!stack && flag == RRA)
		ft_printf("rra\n");
	else if (!stack && flag == RRB)
		ft_printf("rrb\n");
	else if (!stack && flag == RR)
		ft_printf("rr\n");
	else if (!stack && flag == RRR)
		ft_printf("rrr\n");
}

void	print_error(void)
{
	write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
}
