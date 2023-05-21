/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:19:35 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/04 21:00:25 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_find_home(t_env *custom_env)
{
	t_env	*temp;

	temp = custom_env;
	while (temp)
	{
		if (!ft_strcmp(temp->key, "HOME"))
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

void	ft_add_home(t_data *parsing_data, t_env *custom_env)
{
	char	*origin_path;

	if (parsing_data->argv[1] && !ft_strncmp(parsing_data->argv[1], "~", 1))
	{
		origin_path = ft_substr(parsing_data->argv[1], 1, \
		ft_strlen(parsing_data->argv[1]) - 1);
		free(parsing_data->argv[1]);
		parsing_data->argv[1] = ft_strjoin(ft_find_home(custom_env), \
		origin_path);
		free(origin_path);
	}
	else
	{
		ft_double_free(parsing_data->argv);
		parsing_data->argv = (char **)malloc(sizeof(char *) * 3);
		parsing_data->argv[0] = ft_strdup("cd");
		parsing_data->argv[1] = ft_strdup(ft_find_home(custom_env));
		parsing_data->argv[2] = NULL;
	}	
}

int	ft_set_home(t_data *parsing_data, t_env *custom_env, char *origin_wd)
{
	if (!ft_find_home(custom_env))
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
		if (origin_wd)
			free(origin_wd);
		return (1);
	}
	else
		ft_add_home(parsing_data, custom_env);
	return (0);
}

int	ft_print_error_cd(char *argv)
{
	if (!argv)
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot", \
		STDERR_FILENO);
		ft_putstr_fd(" access parent directories: No such file or directory\n", \
		STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(argv, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	return (0);
}
