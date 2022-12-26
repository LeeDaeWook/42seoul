#include "libft.h"

void	ft_putnbr_fd_un(unsigned int n, int fd)
{
	char	temp;

	temp = n % 10 + '0';
	if (n / 10 > 0)
		ft_putnbr_fd_un(n / 10, fd);
	write(fd, &temp, 1);
}
