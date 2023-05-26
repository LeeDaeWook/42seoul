/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:56:52 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/03 15:27:29 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_main_process(t_data **p_data, int *fd, int size, t_exec_vars *e_var)
{
	if ((*p_data)->is_heredoc)
		close(e_var->filedes_here[0]);
	signal(SIGINT, sig_handler_excute);
	if (e_var->prev_fd != -1)
		close(e_var->prev_fd);
	if (size)
	{
		close(fd[1]);
		e_var->prev_fd = fd[0];
		*p_data = (*p_data)->next;
	}
}

void	ft_sub_end(t_data *p_data, int prev_fd, t_env *envp, int *fdes_here)
{
	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	ft_redirection(p_data, fdes_here);
	if (ft_check_built_in(p_data))
	{
		ft_excute_built_in(p_data, envp);
		exit(g_exit_state);
	}
	else
		ft_execve(p_data->path, p_data, envp);
}

void	ft_sub(t_data *p_data, int *fdes, t_exec_vars *e_vars, t_env *envp)
{
	if (e_vars->prev_fd != -1)
	{
		dup2(e_vars->prev_fd, STDIN_FILENO);
		close(e_vars->prev_fd);
	}
	dup2(fdes[1], STDOUT_FILENO);
	ft_redirection(p_data, e_vars->filedes_here);
	close(fdes[0]);
	close(fdes[1]);
	if (ft_check_built_in(p_data))
	{
		ft_excute_built_in(p_data, envp);
		exit(g_exit_state);
	}
	else
		ft_execve(p_data->path, p_data, envp);
}
