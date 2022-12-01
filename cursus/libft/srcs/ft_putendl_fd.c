/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:26:27 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 20:09:07 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int	fd;
	char	s[] = "zzzzzzz12345";

	fd = open("file", O_WRONLY | O_CREAT, 0777);
	ft_putendl_fd(s, fd);

	return (0);
}
*/
