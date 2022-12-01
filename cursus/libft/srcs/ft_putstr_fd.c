/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:15:12 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 20:10:49 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int	fd;
	char	s[] = "abcdef";

	fd = open("file", O_WRONLY | O_CREAT, 0777);
	ft_putstr_fd(s, fd);

	return (0);
}
*/
