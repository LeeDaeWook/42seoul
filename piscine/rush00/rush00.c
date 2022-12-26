/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehyle <junehyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:29:20 by junehyle          #+#    #+#             */
/*   Updated: 2022/10/01 21:38:18 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	example(int x, int y, int col, int row)
{
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
