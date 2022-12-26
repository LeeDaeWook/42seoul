/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:18:26 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/11 21:18:49 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		result;
	int		*array;
	int		i;

	i = 0;
	result = max - min;
	if (min >= max)
	{
		range[0] = NULL;
		return (0);
	}
	array = (int *)malloc(sizeof(int) * (max - min));
	if (array == NULL)
		return (-1);
	while (min < max)
	{
		*(array + i) = min++;
		i++;
	}
	*range = array;
	return (result);
}
