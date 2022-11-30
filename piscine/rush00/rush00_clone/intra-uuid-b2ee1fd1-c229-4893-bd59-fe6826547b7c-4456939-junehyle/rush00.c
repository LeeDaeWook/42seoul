/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehyle <junehyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:29:20 by junehyle          #+#    #+#             */
/*   Updated: 2022/10/02 20:06:45 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_atoi(char *str)
{
	long	l;
	int		i;
	int		sign;

	i = 0;
	l = 0;
	sign = 1;
	/*
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	*/
	while (*str >= '0' && *str <= '9')
	{
		l = l * 10 + (*str - '0');
		str++;
	}
	l *= sign;
	return ((int) l);
}

void	example(int x, int y, int col, int row)
{
	row = 0;
	while (y > row)
	{
		col = 0;
		while (x > col)
		{
			if (row == 0 || row == (y - 1))
			{
				if (col == 0 || col == (x - 1))
					ft_putchar('o');
				else
					ft_putchar('-');
			}
			else
			{
				if (col == 0 || col == (x - 1))
					ft_putchar('|');
				else
					ft_putchar(' ');
			}
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	rush(int x, int y)
{
	example(x, y, 0, 0);
}	
