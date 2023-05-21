/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:25:52 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 15:47:39 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_data *parsing_data, t_env *custom_env)
{
	t_env	*temp;
	t_env	*deleted_node;
	int		i;

	i = 1;
	while (parsing_data->argv[i])
	{
		temp = custom_env;
		while (temp)
		{
			if (temp->next && !ft_strcmp(temp->next->key, \
			parsing_data->argv[i]))
			{
				deleted_node = temp->next;
				temp->next = temp->next->next;
				ft_free_env(deleted_node);
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
	return (0);
}
