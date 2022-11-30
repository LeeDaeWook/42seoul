/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:35:05 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/24 20:42:48 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putnbr_fd(int n, int fd)
{
	char	temp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	temp = n % 10 + '0';
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &temp, 1);
}

/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int	fd;

	fd = open("file_putnbr_fd", O_WRONLY | O_CREAT, 0777);
	ft_putnbr_fd(-2147483648, fd);

	return (0);
}
*/
