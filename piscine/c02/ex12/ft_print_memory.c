/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:52:44 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/03 22:13:49 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_str(unsigned char *addr, unsigned int size, unsigned int *i)
{
	unsigned int	count;

	count = 0;
	while (count < 16 && (*i + count) < size)
	{
		if (addr[*i + count] >= 32 && addr[*i + count] <= 126)
			write(1, addr + *i + count, 1);
		else
			write(1, ".", 1);
		count++;
	}
	write(1, "\n", 1);
}

void	ft_print_hex(unsigned char *addr, unsigned int size, unsigned int *i)
{
	char				*hex;
	unsigned int		count;

	hex = "0123456789abcdef";
	count = 0;
	while (count < 16)
	{
		if ((*i + count) < size)
		{
			write(1, &hex[*(addr + *i + count) / 16], 1);
			write(1, &hex[*(addr + *i + count) % 16], 1);
		}
		else
			write(1, "  ", 2);
		count++;
		if (count % 2 == 0)
			write(1, " ", 1);
	}
	ft_print_str(addr, size, i);
	*i += count;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long	addr_l;
	unsigned int		i;
	int					j;
	char				*hex;
	char				addr_str[17];

	hex = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		addr_l = (unsigned long long)(addr + i);
		j = 0;
		while (j++ < 16)
		{
			addr_str[16 - j] = hex[addr_l % 16];
			addr_l /= 16;
		}
		write(1, addr_str, j);
		write(1, ": ", 2);
		ft_print_hex(addr, size, &i);
	}
	return (addr);
}
