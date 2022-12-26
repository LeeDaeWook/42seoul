/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:12:30 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/16 20:37:37 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void	putfile(int fd, char *argv[])
{
	int		len = 20;
	char	buf[20];
	ssize_t	ret_val;

	while ((ret_val = read(fd, buf, len)) != 0)
	{
		if (ret_val == -1)
		{
			write(2, "ft_cat: ", 8);
			write(2, basename(argv[1]), ft_strlen(basename(argv[1])));
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(1, "\n", 1);
			return ;
		}
		write(1, buf, ret_val);
	}
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(1, "\n", 1);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "ft_cat: ", 8);
		write(2, basename(argv[1]), ft_strlen(basename(argv[1])));
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(1, "\n", 1);
	}
	else
		putfile(fd, argv);

	close(fd);
	return (0);
}
