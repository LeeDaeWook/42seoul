/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:46:47 by daewoole          #+#    #+#             */
/*   Updated: 2022/09/29 23:44:09 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		validate_overlap(char*s, int col);
void	ft_recursive(char*s, int n, int col, int idx);

void	ft_print_combn(int n)
{
	char	s[9];

	ft_recursive(s, n, 0, 0);
}

void	ft_recursive(char*s, int n, int col, int idx)
{
	int	i;

	i = 0;
	if (col == n)
	{
		while (i < n)
		{
			write(1, &s[i], 1);
			i++;
		}
		if (s[0] == (10 - n + '0'))
			return ;
		write(1, ", ", 2);
	}
	else
	{
		while (idx < 10)
		{
			s[col] = idx + '0';
			if (validate_overlap(s, col))
				ft_recursive(s, n, col + 1, idx + 1);
			idx++;
		}
	}
}

int	validate_overlap(char*s, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (s[i] == s[col])
			return (0);
		i++;
	}
	return (1);
}
