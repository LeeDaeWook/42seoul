/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:25:40 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 15:47:12 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(t_data *parsing_data, t_env *custom_env)
{
	int		i;
	t_env	*new_node;
	t_env	*new_list;

	i = 1;
	while (parsing_data->argv[i])
	{
		if (ft_valid_data(parsing_data->argv[i]))
		{
			ft_putstr_fd("minishell: export: ", STDERR_FILENO);
			ft_putstr_fd(parsing_data->argv[i], STDERR_FILENO);
			ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
			return (1);
		}
		new_node = env_lstnew(parsing_data->argv[i]);
		env_lstadd_back(&custom_env, new_node);
		i++;
	}
	if (i == 1)
	{
		new_list = ft_duplicate_list(custom_env);
		ft_mergesort(&new_list);
		ft_print_env(new_list);
	}
	return (0);
}
