/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:11:40 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 14:38:24 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_count(int **count, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(count[i]);
		i++;
	}
	free(count);
}

void	double_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_linked_list(t_deque *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		free(temp);
		temp = temp->next;
	}
}
