/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:33:15 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/06 17:47:38 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	val(int *board, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == board[col])
			return (0);
		if ((board[col] > board[i]) && board[col] - board[i] == col - i)
			return (0);
		if ((board[i] > board[col]) && board[i] - board[col] == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	recur(int *board, int col, int *count)
{
	int	idx;

	idx = 0;
	if (col == 10)
	{
		print(board);
		*count += 1;
		return ;
	}
	while (idx < 10)
	{
		board[col] = idx;
		if (val(board, col))
			recur(board, col + 1, count);
		idx++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	recur(board, 0, &count);
	return (count);
}
