/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:55:38 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/03 14:32:37 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtin_for_parents(char **argv)
{
	int	flag;

	flag = 0;
	if (!argv)
		return (flag);
	if (!ft_strcmp(argv[0], "export"))
		flag = 1;
	else if (!ft_strcmp(argv[0], "cd"))
		flag = 1;
	else if (!ft_strcmp(argv[0], "exit"))
		flag = 1;
	else if (!ft_strcmp(argv[0], "unset"))
		flag = 1;
	return (flag);
}

void	init(int argc, char **argv, char **env, t_env **custom_env)
{
	(void)argc;
	(void)argv;
	while (*env)
		env_lstadd_back(custom_env, env_lstnew(*env++));
	signal(SIGQUIT, SIG_IGN);
}

void	ft_wait_process(int size, pid_t pid)
{
	int	flag;

	flag = 0;
	while (size--)
		ft_wait(pid, &flag);
}

char	*ft_get_line(t_env *envp)
{
	char	*line;

	line = readline("minishell$ ");
	if (!line)
	{
		ft_putstr_fd("\x1b[1A", STDOUT_FILENO);
		ft_putstr_fd("\033[11C", STDOUT_FILENO);
		t_env_lstclear(&envp);
		ft_exit(NULL);
	}
	if (!(*line))
	{
		free(line);
		return (NULL);
	}
	if (line)
		add_history(line);
	return (line);
}

t_data	*ft_parsing_process(char *line, t_env *envp)
{
	t_data	*parsing_node;
	t_data	*p;

	if (!line)
		return (NULL);
	if (ft_check_quote(line))
		return (NULL);
	parsing_node = NULL;
	parsing_node = ft_parsing_pipe(line, parsing_node, 0);
	parsing_node = ft_check_pipe(line, parsing_node);
	p = parsing_node;
	while (p)
	{
		p = ft_parse(p, envp);
		if (!p)
			return (NULL);
		p = p->next;
	}
	parsing_node = ft_path(parsing_node, envp);
	return (parsing_node);
}
