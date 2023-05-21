/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:20:31 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/04 20:58:55 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_oldpwd(t_env *custom_env)
{
	t_env	*temp;
	char	*temp_str;
	int		flag;

	temp = custom_env;
	flag = 0;
	while (temp)
	{
		if (!ft_strcmp(temp->key, "OLDPWD"))
		{
			flag = 1;
			break ;
		}
		temp = temp->next;
	}
	if (!flag)
	{
		temp_str = ft_strjoin("OLDPWD", "=");
		temp = env_lstnew(temp_str);
		free(temp_str);
		env_lstadd_back(&custom_env, temp);
	}
}

char	*ft_add_str(char *content, char *value)
{
	char	*temp_content;

	temp_content = content;
	content = ft_strjoin(content, value);
	free(temp_content);
	return (content);
}

void	ft_search_key(char *origin_wd, t_env *custom_env)
{
	t_env	*temp;

	temp = custom_env;
	while (temp)
	{
		if (!ft_strcmp(temp->key, "PWD"))
		{
			free(temp->value);
			temp->value = getcwd(NULL, 0);
			free(temp->content);
			temp->content = ft_strjoin(temp->key, "=");
			temp->content = ft_add_str(temp->content, temp->value);
		}
		else if (!ft_strcmp(temp->key, "OLDPWD") && origin_wd)
		{
			if (temp->value)
				free(temp->value);
			temp->value = origin_wd;
			free(temp->content);
			temp->content = ft_strjoin(temp->key, "=");
			temp->content = ft_add_str(temp->content, temp->value);
		}
		temp = temp->next;
	}
}

void	ft_not_moving(char *origin_wd, char *argv)
{
	if (!ft_strcmp(argv, "$HOME"))
		ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
	else
		ft_print_error_cd(argv);
	if (origin_wd)
		free(origin_wd);
}

int	ft_cd(t_data *parsing_data, t_env *custom_env)
{
	char	*origin_wd;
	int		ret_val;

	ft_check_oldpwd(custom_env);
	origin_wd = getcwd(NULL, 0);
	if (!origin_wd && parsing_data->argv[1] && \
	!ft_strcmp(parsing_data->argv[1], "."))
		return (ft_print_error_cd(NULL));
	if ((parsing_data->argv[1] && !ft_strncmp(parsing_data->argv[1], "~", 1)) \
	|| !parsing_data->argv[1])
	{
		ret_val = ft_set_home(parsing_data, custom_env, origin_wd);
		if (ret_val)
			return (ret_val);
	}
	if (!chdir(parsing_data->argv[1]))
		ft_search_key(origin_wd, custom_env);
	else
	{
		ft_not_moving(origin_wd, parsing_data->argv[1]);
		return (1);
	}
	return (0);
}
