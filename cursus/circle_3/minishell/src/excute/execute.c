/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:18:59 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/03 20:36:14 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe(int *filedes)
{
	if (pipe(filedes) == -1)
	{
		perror(NULL);
		g_exit_state = errno;
		exit(errno);
	}
}

void	ft_execve(char *path, t_data *parsing_data, t_env *envp)
{
	char	**lst_envp;

	ft_reset_termios();
	signal(SIGQUIT, SIG_DFL);
	lst_envp = ft_list_to_arr(envp);
	if (!parsing_data->argv)
		exit(EXIT_SUCCESS);
	if (execve(path, parsing_data->argv, lst_envp) == -1)
	{
		if (ft_is_directory(path, parsing_data))
		{
			if (errno != 13)
				ft_check_path(path, parsing_data, envp);
		}
		ft_putstr_fd("minishell: ", 2);
		perror(parsing_data->argv[0]);
		exit(EXIT_FAILURE);
	}
}

int	ft_check_built_in(t_data *parsing_data)
{
	char	*str;
	int		is_built_in;

	if (!parsing_data->argv)
		return (0);
	str = ft_strdup(parsing_data->argv[0]);
	ft_tolower_env(str);
	is_built_in = 0;
	if (!ft_strcmp(parsing_data->argv[0], "export"))
		is_built_in = 1;
	else if (!ft_strcmp(str, "env"))
		is_built_in = 1;
	else if (!ft_strcmp(str, "echo"))
		is_built_in = 1;
	else if (!ft_strcmp(parsing_data->argv[0], "cd"))
		is_built_in = 1;
	else if (!ft_strcmp(parsing_data->argv[0], "exit"))
		is_built_in = 1;
	else if (!ft_strcmp(str, "pwd"))
		is_built_in = 1;
	else if (!ft_strcmp(parsing_data->argv[0], "unset"))
		is_built_in = 1;
	free(str);
	return (is_built_in);
}

void	ft_excute_built_in(t_data *parsing_data, t_env *custom_env)
{
	char	*str;

	if (!parsing_data->argv)
		return ;
	str = ft_strdup(parsing_data->argv[0]);
	ft_tolower_env(str);
	if (!ft_strcmp(parsing_data->argv[0], "export"))
		g_exit_state = ft_export(parsing_data, custom_env);
	else if (!ft_strcmp(str, "env"))
		g_exit_state = ft_env(custom_env, parsing_data->argv);
	else if (!ft_strcmp(str, "echo"))
		g_exit_state = ft_echo(parsing_data, 1);
	else if (!ft_strcmp(parsing_data->argv[0], "cd"))
		g_exit_state = ft_cd(parsing_data, custom_env);
	else if (!ft_strcmp(parsing_data->argv[0], "exit"))
		ft_exit(parsing_data);
	else if (!ft_strcmp(str, "pwd"))
		g_exit_state = ft_pwd();
	else if (!ft_strcmp(parsing_data->argv[0], "unset"))
		g_exit_state = ft_unset(parsing_data, custom_env);
	free(str);
}

void	ft_excute(t_data *p_data, int size, t_env *envp)
{
	pid_t		pid;
	int			filedes[2];
	t_exec_vars	e_vars;

	e_vars.prev_fd = -1;
	e_vars.t_size = size;
	while (size-- && e_vars.t_size)
	{
		if (size)
			ft_pipe(filedes);
		if (ft_heredoc_parents(p_data->rd, e_vars.filedes_here, envp))
			return (close_fd_heredoc(&e_vars, filedes, size));
		pid = fork();
		if (!pid && !size)
			ft_sub_end(p_data, e_vars.prev_fd, envp, e_vars.filedes_here);
		else if (!pid)
			ft_sub(p_data, filedes, &e_vars, envp);
		else
			ft_main_process(&p_data, filedes, size, &e_vars);
	}
	ft_wait_process(e_vars.t_size, pid);
}
