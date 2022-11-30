/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:36:31 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/16 20:27:55 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

void	putfile(int fd)
{
	int		len = 10;
	char	buf[10];
	ssize_t	ret_val;

	while ((ret_val = read(fd, buf, len)) != 0)
	{
		if (ret_val == -1)
		{
			write(1, "Cannot read file.", 17);
			return ;
		}
		write(1, buf, ret_val);
	}
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc == 1)
	{
		write(1, "File name missing.", 18);
		return (0);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.", 19);
		return (0);
	}
	
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		write(1, "Cannot read file.", 17);	
	putfile(fd);
	close(fd);
	return (0);
}
