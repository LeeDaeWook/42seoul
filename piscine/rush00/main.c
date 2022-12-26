/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehyle <junehyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:49:58 by junehyle          #+#    #+#             */
/*   Updated: 2022/10/01 19:08:54 by junehyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int		ft_atoi(char *str);
void	ft_putchar(char c);

int	main(int argc, char *argv[])
{
	int	n1;
	int	n2;

	if (argc != 1)
	{
		n1 = ft_atoi(argv[1]);
		n2 = ft_atoi(argv[2]);
		rush(n1, n2);
	}
	rush(5, 3);
	write (1, "\n", 1);
	rush(5, 1);
	write (1, "\n", 1);
	rush(1, 1);
	write (1, "\n", 1);
	rush(1, 5);
	write (1, "\n", 1);
	rush(4, 4);
	write (1, "\n", 1);
	rush(123, 42);
	write (1, "\n", 1);
	return (0);
}
