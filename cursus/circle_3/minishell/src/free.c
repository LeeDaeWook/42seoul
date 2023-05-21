/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:06:34 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/03/31 20:11:18 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_double_free(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i])
			free(argv[i]);
		i++;
	}
	free(argv);
}
