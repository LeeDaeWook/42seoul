/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:01:30 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/24 20:14:56 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int	fd;

	fd = open("file", O_WRONLY | O_CREAT, 0777);
	ft_putchar_fd('7', fd);

	return (0);
}
*/
