/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:36:36 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/04 13:12:09 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc_child(int *filedes)
{
	dup2(filedes[0], STDIN_FILENO);
	close(filedes[0]);
	close(filedes[1]);
}

void	close_fd_heredoc(t_exec_vars *e_vars, int *filedes, int size)
{
	if (size)
	{
		close(filedes[0]);
		close(filedes[1]);
	}
	close(e_vars->filedes_here[0]);
}

int	ft_waitpid_heredoc(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exit_state = WEXITSTATUS(status);
	else
	{
		if (status == 2)
		{
			g_exit_state = 1;
			return (1);
		}
		else
			g_exit_state = status;
	}
	return (0);
}

void	ft_fork_heredoc(t_rd *rd, int *filedes, t_env *envp)
{
	char	*limit;
	char	*buf;

	limit = ft_strjoin(rd->argument, "\n");
	signal(SIGINT, SIG_DFL);
	buf = ft_heredoc_get_line(limit);
	if (buf)
	{
		if (!rd->is_quote)
			buf = ft_handling_env(buf, envp);
		ft_putstr_fd(buf, filedes[1]);
	}
	close(filedes[0]);
	close(filedes[1]);
	free(buf);
	free(limit);
	exit(EXIT_SUCCESS);
}

char	*ft_heredoc_get_line(char *limit)
{
	char	*line;
	char	*buf;
	char	*temp;

	line = NULL;
	buf = NULL;
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line || !ft_strcmp(line, (char *)limit))
			break ;
		if (!buf)
			buf = ft_strdup(line);
		else
		{
			temp = buf;
			buf = ft_strjoin(buf, line);
			free(temp);
		}
		free(line);
	}
	if (line)
		free(line);
	return (buf);
}
