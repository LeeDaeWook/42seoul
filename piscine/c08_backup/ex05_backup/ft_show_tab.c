/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:33:22 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/11 14:24:17 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	strlen;

	i = 0;
	while (par[i].str != 0)
	{
		strlen = par[i].size;
		par[i].size += '0';
		write(1, par[i].str, strlen);
		write(1, "\n", 1);
		write(1, &(par[i].size), 1);
		write(1, "\n", 1);
		write(1, par[i].copy, strlen);
		write(1, "\n", 1);
		i++;
	}
}
