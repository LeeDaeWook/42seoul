/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:50:37 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/16 19:49:15 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft.h"

int	calc(int cur_op, char *argv[])
{
	if (cur_op == 0)
		return (add(ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (cur_op == 1)
		return (sub(ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (cur_op == 2)
		return (mul(ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (cur_op == 3)
	{
		if (ft_atoi(argv[3]) == 0)
		{
			write(1, "Stop : division by zero", 23);
			return (-1);
		}
		return (div(ft_atoi(argv[1]), ft_atoi(argv[3])));
	}
	else if (cur_op == 4)
	{
		if (ft_atoi(argv[3]) == 0)
		{
			write(1, "Stop : modulo by zero", 21);
			return (-1);
		}
		return (mod(ft_atoi(argv[1]), ft_atoi(argv[3])));
	}
	return (0);
}

int	find_operator(char *argv[])
{
	int		cur_op;
	int		i;
	char	*operator;

	operator = "+-*/%";
	cur_op = 5;
	i = 0;
	while (i < 5)
	{
		if (*argv[2] == operator[i])
			cur_op = i;
		i++;
	}
	return (calc(cur_op, argv));
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	if (find_operator(argv) != -1)
		ft_putnbr(find_operator(argv));
	write(1, "\n", 1);
	return (0);
}
