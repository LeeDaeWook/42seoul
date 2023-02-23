/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_un.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:48:12 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/05 13:48:15 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_fd_un(unsigned int n, int fd)
{
	char	temp;

	temp = n % 10 + '0';
	if (n / 10 > 0)
		ft_putnbr_fd_un(n / 10, fd);
	write(fd, &temp, 1);
}
