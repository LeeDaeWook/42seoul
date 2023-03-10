/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excute_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:42:44 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/11 07:42:53 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_num(unsigned long long num, char*format, int*ret_val)
{
	if (*format == 'd' || *format == 'i')
	{
		ft_putnbr_fd(num, 1);
		*ret_val += ft_len(num);
	}
	else if (*format == 'u')
	{
		ft_putnbr_fd_un(num, 1);
		*ret_val += ft_len(num);
	}
	else if (*format == 'p' || *format == 'x' || *format == 'X')
	{
		if (*format == 'p')
			*ret_val += write(1, "0x", 2);
		ft_putnbr_base(num, ret_val, format);
	}
}

void	ft_print_str(char*str, int*ret_val)
{
	if (!str)
	{
		ft_putstr_fd((char *)"(null)", 1);
		*ret_val += ft_strlen("(null)");
		return ;
	}
	ft_putstr_fd(str, 1);
	*ret_val += ft_strlen(str);
}

void	ft_print_char(int c, int*ret_val)
{
	ft_putchar_fd(c, 1);
	*ret_val += 1;
}
