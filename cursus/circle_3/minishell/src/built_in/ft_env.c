/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:25:12 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 15:49:14 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env *custom_env, char **argv)
{
	t_env	*temp;
	int		i;

	temp = custom_env;
	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "env"))
		{
			ft_putstr_fd("minishell: env: ", STDERR_FILENO);
			ft_putstr_fd(argv[i], STDERR_FILENO);
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
			return (127);
		}
		i++;
	}
	while (temp)
	{
		if (temp->key && ft_strchr(temp->content, '='))
			printf("%s\n", temp->content);
		temp = temp->next;
	}
	return (0);
}
