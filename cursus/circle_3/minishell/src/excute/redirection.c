/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:26:03 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/04 13:13:19 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_other_redirection(char *argument, int std_fd, int option)
{
	int	fd;

	fd = open(argument, option, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(argument);
		exit(EXIT_FAILURE);
	}
	dup2(fd, std_fd);
	close(fd);
}

void	ft_redirection(t_data *parsing_data, int *filedes)
{
	t_rd	*rd;

	rd = parsing_data->rd;
	while (rd)
	{
		if (rd->type == IN)
			ft_other_redirection(rd->argument, STDIN_FILENO, O_RDONLY);
		else if (rd->type == OUT)
			ft_other_redirection(rd->argument, STDOUT_FILENO, \
								O_WRONLY | O_TRUNC | O_CREAT);
		else if (rd->type == HEREDOC)
			ft_heredoc_child(filedes);
		else if (rd->type == APPEND)
			ft_other_redirection(rd->argument, STDOUT_FILENO, \
								O_WRONLY | O_APPEND | O_CREAT);
		rd = rd->next;
	}
}

int	ft_heredoc_parents(t_rd *rd, int *filedes, t_env *envp)
{
	pid_t	pid;

	while (rd)
	{
		if (rd->type == HEREDOC)
		{
			pipe(filedes);
			pid = fork();
			if (!pid)
				ft_fork_heredoc(rd, filedes, envp);
			else
			{
				signal(SIGINT, sig_handler_excute);
				if (ft_waitpid_heredoc(pid))
					return (1);
				close(filedes[1]);
			}
		}
		rd = rd->next;
	}
	return (0);
}

char	*ft_handling_env(char *buf, t_env *custom_env)
{
	int		count;
	int		total_size;
	char	*new_buf;

	if (!buf)
		return (NULL);
	count = ft_env_dollar_count(buf);
	while (count--)
	{
		total_size = ft_total_size(buf, custom_env);
		new_buf = (char *)malloc(sizeof(char) * (total_size + 1));
		if (!new_buf)
			ft_malloc_exit();
		buf = ft_env_converter(buf, new_buf, NULL, custom_env);
	}
	return (buf);
}
