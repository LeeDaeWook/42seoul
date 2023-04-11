/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:30:22 by daewoole          #+#    #+#             */
/*   Updated: 2023/03/14 16:30:25 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	validate_instructions(char *instruction)
{
	if (!ft_strcmp(instruction, "ra\n") || !ft_strcmp(instruction, "rb\n"))
		return (0);
	else if (!ft_strcmp(instruction, "rra\n") || !ft_strcmp(instruction, "rrb\n"))
		return (0);
	else if (!ft_strcmp(instruction, "rr\n") || !ft_strcmp(instruction, "rrr\n"))
		return (0);
	else if (!ft_strcmp(instruction, "sa\n") || !ft_strcmp(instruction, "sb\n"))
		return (0);
	else if (!ft_strcmp(instruction, "pa\n") || !ft_strcmp(instruction, "pb\n"))
		return (0);
	else
		return (1);
}
