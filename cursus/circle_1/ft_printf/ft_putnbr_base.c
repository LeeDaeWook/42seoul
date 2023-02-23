/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:48:01 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/11 07:44:04 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nbr, int *ret_val, char *format)
{
	int		base_len;
	char	c;
	char	*base;

	base = "0123456789abcdef";
	if (*format == 'X')
		base = "0123456789ABCDEF";
	base_len = 0;
	while (*(base + base_len))
		base_len++;
	c = base[nbr % base_len];
	*ret_val += 1;
	if ((nbr / base_len) == 0)
	{
		write(1, &c, 1);
		return ;
	}
	ft_putnbr_base(nbr / base_len, ret_val, format);
	write(1, &c, 1);
}
