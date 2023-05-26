/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:36:23 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/03 14:51:15 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_state;

int	main(int argc, char *argv[], char **env)
{
	char	*line;
	t_data	*parsing_data;
	int		size;
	t_env	*custom_env;

	custom_env = NULL;
	init(argc, argv, env, &custom_env);
	while (1)
	{
		signal(SIGINT, sig_handler);
		ft_set_termios();
		line = ft_get_line(custom_env);
		parsing_data = ft_parsing_process(line, custom_env);
		parsing_data = ft_check_syntax(parsing_data);
		free(line);
		if (!parsing_data)
			continue ;
		size = t_data_lstsize(parsing_data);
		if (size == 1 && ft_builtin_for_parents(parsing_data->argv))
			ft_excute_built_in(parsing_data, custom_env);
		else
			ft_excute(parsing_data, size, custom_env);
		t_data_lstclear(&parsing_data);
	}
	exit(0);
}
