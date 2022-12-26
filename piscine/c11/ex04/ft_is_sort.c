/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:24:24 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/17 21:27:22 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	acs;
	int	dec;

	i = 0;
	acs = 0;
	dec = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			dec++;
		else if ((*f)(tab[i], tab[i + 1]) < 0)
			acs++;
		else
		{
			dec++;
			acs++;
		}
		i++;
	}
	if (acs == i || dec == i)
		return (1);
	return (0);
}
