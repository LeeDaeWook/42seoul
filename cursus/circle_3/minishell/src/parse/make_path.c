/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:21:37 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 15:27:32 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *key, t_env *envp)
{
	t_env	*p;

	p = envp;
	while (p)
	{
		if (!ft_strcmp(key, p->key))
			return (p->value);
		p = p->next;
	}
	return (NULL);
}

t_data	*ft_path(t_data *parsing_data, t_env *envp)
{
	char	*get_env_path;
	char	**env_path;
	t_data	*p;

	get_env_path = ft_getenv("PATH", envp);
	env_path = upd_split(get_env_path, ':');
	if (!env_path)
	{
		t_data_lstclear(&parsing_data);
		return (NULL);
	}
	p = parsing_data;
	while (p)
	{
		if (p->argv)
			p->path = ft_find_path(env_path, p->argv[0]);
		p = p->next;
	}
	ft_double_free(env_path);
	return (parsing_data);
}

char	*ft_find_path(char **env_path, char *cmd)
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	path = NULL;
	while (env_path[i])
	{
		temp = ft_strjoin(env_path[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		temp = NULL;
		if (!access(path, F_OK))
			return (path);
		free(path);
		path = NULL;
		i++;
	}
	path = ft_strdup(cmd);
	return (path);
}
