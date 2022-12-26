/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:14:33 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/05 19:10:12 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	if (!(*base) || !(*(base + 1)))
		return (0);
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		if (*(base + i) == *(base + i + 1))
			return (0);
		i++;
	}
	return (1);
}

unsigned int	ft_unsign_nbr(int nbr, char *base)
{
	unsigned int	un_nbr;

	un_nbr = 0;
	if (ft_check_base(base))
	{
		if (nbr < 0)
		{
			un_nbr = (unsigned int) nbr * -1;
			write(1, "-", 1);
		}
		else
			un_nbr = (unsigned int) nbr;
	}
	return (un_nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;
	char			c;
	unsigned int	un_nbr;

	base_len = 0;
	un_nbr = ft_unsign_nbr(nbr, base);
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	while (*(base + base_len))
		base_len++;
	if (un_nbr > 0)
	{
		c = base[un_nbr % base_len];
		if ((un_nbr / base_len) == 0)
		{
			write(1, &c, 1);
			return ;
		}
		ft_putnbr_base(un_nbr / base_len, base);
		write(1, &c, 1);
	}
}
