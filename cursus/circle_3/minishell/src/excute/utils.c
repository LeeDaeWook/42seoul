/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:26:09 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/03 14:52:12 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_list_to_arr(t_env *envp)
{
	char	**temp_arr;
	int		i;

	temp_arr = (char **)malloc(sizeof(char *) * (t_env_lstsize(envp) + 1));
	if (!temp_arr)
		ft_malloc_exit();
	i = 0;
	while (envp)
	{
		temp_arr[i] = ft_strdup(envp->content);
		envp = envp->next;
		i++;
	}
	temp_arr[i] = NULL;
	return (temp_arr);
}

void	ft_tolower_env(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

int	ft_is_directory(char *path, t_data *parsing_data)
{
	struct stat	sb;

	stat(path, &sb);
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(parsing_data->argv[0], 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit(126);
	}
	return (1);
}

void	ft_check_path(char *path, t_data *parsing_data, t_env *envp)
{
	if (!ft_getenv("PATH", envp))
	{
		ft_putstr_fd("minishell: ", 2);
		perror(parsing_data->argv[0]);
		exit(127);
	}
	if (access(path, F_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(parsing_data->argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	if (access(path, X_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(parsing_data->argv[0]);
		exit(126);
	}
}

void	ft_wait(pid_t pid, int *flag)
{
	int	status;
	int	is_pid;

	is_pid = wait(&status);
	if (is_pid == pid)
	{
		if (WIFEXITED(status))
			g_exit_state = WEXITSTATUS(status);
		else
		{
			if (status == 3 && !(*flag))
			{
				*flag = 1;
				printf("Quit: %d\n", status);
			}
			else if (status == 2 && !(*flag))
				*flag = 1;
			g_exit_state = status + 128;
		}
	}
}
