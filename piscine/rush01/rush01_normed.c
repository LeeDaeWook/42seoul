/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyolee <kiyolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:53:30 by kiyolee           #+#    #+#             */
/*   Updated: 2022/10/09 15:51:05 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_print(int **result, int input_n);
int		validate_overlap(int idx, int col, int **result);
void	ft_loop(int **result, int *input, int input_n, int col, int idx);

int	upcol_condition(int **result, int *input, int input_n)
{
	int	row;
	int	col;
	int	box_count;
	int	input_idx;
	int	temp;

	col = 0;
	input_idx = input_n * 0;
	while (col < input_n)
	{
		box_count = 1;
		row = 0;
		temp = result[row][col];
		while (row + 1 < input_n)
		{
			if (temp < result[row + 1][col])
			{
				box_count++;
				temp = result[row + 1][col];
			}
			row++;
		}
		col++;
		if (box_count == input[input_idx])
			input_idx++;
		else
			return (0);
	}
	return (1);
}

int	downcol_condition(int **result, int *input, int input_n)
{
	int	row;
	int	col;
	int	box_count;
	int	input_idx;
	int	temp;

	col = 0;
	input_idx = input_n * 1;
	while (col < input_n)
	{
		box_count = 1;
		row = input_n - 1;
		temp = result[row][col];
		while (row > 0)
		{
			if (result[row - 1][col] > temp)
			{
				box_count++;
				temp = result[row - 1][col];
			}
			row--;
		}
		col++;
		if (box_count == input[input_idx])
			input_idx++;
		else
			return (0);
	}
	return (1);
}

int	lrow_condition(int **result, int *input, int input_n)
{
	int	row;
	int	col;
	int	box_count;
	int	input_idx;
	int	temp;

	row = 0;
	input_idx = input_n * 2;
	while (row < input_n)
	{
		box_count = 1;
		col = 0;
		temp = result[row][col];
		while (col + 1 < input_n)
		{
			if (temp < result[row][col + 1])
			{
				box_count++;
				temp = result[row][col + 1];
			}
			col++;
		}
		row++;
		if (box_count == input[input_idx])
			input_idx++;
		else
			return (0);
	}
	return (1);
}

int	rrow_condition(int **result, int *input, int input_n)
{
	int	row;
	int	col;
	int	box_count;
	int	input_idx;
	int	temp;

	row = 0;
	input_idx = input_n * 3;
	while (row < input_n)
	{
		box_count = 1;
		col = input_n - 1;
		temp = result[row][col];
		while (col > 0)
		{
			if (result[row][col - 1] > temp)
			{
				box_count++;
				temp = result[row][col - 1];
			}
			col--;
		}
		row++;
		if (box_count == input[input_idx])
			input_idx++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	input[36];
	int	**result;
	int	i;
	int	input_n;

	i = 0;
	if (argc == 1)
		return (0);
	while (*argv[1])
	{
		if (*argv[1] != ' ')
		{
			input[i] = *argv[1] - '0';
			i++;
		}
		argv[1]++;
	}
	input_n = i / 4;
	result = (int **)malloc(sizeof(int *) * input_n);
	i = 0;
	while (i < input_n)
	{
		result[i] = (int *)malloc(sizeof(int) * input_n);
		i++;
	}
	ft_loop(result, input, input_n, 0, 0);
	while (--i >= 0)
		free(result[i]);
	free(result);
	return (0);
}

void	ft_print(int **result, int input_n)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < input_n)
	{
		j = 0;
		while (j < input_n)
		{
			c = result[i][j] + '0';
			write(1, &c, 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	validate_overlap(int idx, int col, int **result)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (i != col && result[idx][col] == result[idx][i]) // 가로줄 검사
			return (0);
		i++;
	}
	i = 0;
	while (i < idx)
	{
		if (i != idx && result[idx][col] == result[i][col]) // 세로줄 검사
			return (0);
		i++;
	}
	return (1);
}

void	ft_loop(int **result, int *input, int input_n, int col, int idx)
{
	int	i;

	i = 1;
	if (idx == input_n)
	{
		if (upcol_condition(result, input, input_n)
			&& downcol_condition(result, input, input_n)
			&& lrow_condition(result, input, input_n)
			&& rrow_condition(result, input, input_n))
			ft_print(result, input_n);
		return ;
	}
	if (col == input_n)
	{
		ft_loop(result, input, input_n, 0, idx + 1);
		return ;
	}
	while (i <= input_n)
	{
		result[idx][col] = i;
		if (validate_overlap(idx, col, result))
			ft_loop(result, input, input_n, col + 1, idx);
		i++;
	}
}
