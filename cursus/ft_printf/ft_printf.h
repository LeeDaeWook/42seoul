/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:44:58 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/11 07:47:58 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

long long	ft_len(long long n);
char		*put_type(char*format, va_list*ap, int*ret_val);
int			read_format(char*format, va_list*ap);
int			ft_printf(const char*format, ...);
void		ft_putnbr_base(unsigned long long nbr, int*ret_val, char*format);
void		ft_putnbr_fd_un(unsigned int n, int fd);
void		ft_print_num(unsigned long long num, char*format, int*ret_val);
void		ft_print_str(char*str, int*ret_val);
void		ft_print_char(int c, int*ret_val);

#endif
