/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:21:01 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:36:11 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	double_instructions(t_deque *deque_a, t_deque *deque_b, int flag)
{
	if (flag == RR)
	{
		rotate_checker(deque_a);
		rotate_checker(deque_b);
	}
	else if (flag == RRR)
	{
		reverse_rotate_checker(deque_a);
		reverse_rotate_checker(deque_b);
	}
}

void	ft_instructions(char *instruction, t_deque *deque_a, t_deque *deque_b)
{
	if (validate_instructions(instruction))
		print_error();
	if (!ft_strcmp(instruction, "ra\n"))
		rotate_checker(deque_a);
	else if (!ft_strcmp(instruction, "rb\n"))
		rotate_checker(deque_b);
	else if (!ft_strcmp(instruction, "rr\n"))
		double_instructions(deque_a, deque_b, RR);
	else if (!ft_strcmp(instruction, "rra\n"))
		reverse_rotate_checker(deque_a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		reverse_rotate_checker(deque_b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		double_instructions(deque_a, deque_b, RRR);
	else if (!ft_strcmp(instruction, "pa\n"))
		push_checker(deque_a, deque_b);
	else if (!ft_strcmp(instruction, "pb\n"))
		push_checker(deque_b, deque_a);
	else if (!ft_strcmp(instruction, "sa\n"))
		swap_checker(deque_a);
	else if (!ft_strcmp(instruction, "sb\n"))
		swap_checker(deque_b);
}

void	init(char *argv[], t_deque *deque_a, t_deque *deque_b)
{
	ft_bzero((void *)deque_a, sizeof(t_deque));
	deque_a->top = add_node();
	make_list(++argv, deque_a, 0, deque_a->top);
	deque_a->stack = STACK_A;
	if (!deque_a->size)
		print_error();
	ft_bzero((void *)deque_b, sizeof(t_deque));
	deque_b->stack = STACK_B;
}

int	validate_sort(t_deque *deque)
{
	t_node	*temp;

	temp = deque->top;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_deque	deque_a;
	t_deque	deque_b;
	char	*instruction;

	(void)argc;
	init(argv, &deque_a, &deque_b);
	while (1)
	{
		instruction = get_next_line(STANDARD_INPUT);
		if (!instruction)
			break ;
		ft_instructions(instruction, &deque_a, &deque_b);
		free(instruction);
	}
	if (validate_sort(&deque_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_linked_list(&deque_a);
	return (EXIT_SUCCESS);
}
