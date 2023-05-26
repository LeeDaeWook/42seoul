/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:25:05 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 23:05:35 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_validate_option(char *argv)
{
	int	flag;

	flag = 1;
	argv++;
	while (*argv)
	{
		if (*argv != 'n')
		{
			flag = 0;
			break ;
		}
		argv++;
	}
	return (flag);
}

int	ft_check_null(char *argv)
{
	if (!argv)
	{
		printf("\n");
		return (1);
	}
	return (0);
}

int	ft_echo(t_data *parsing_data, int i)
{
	if (ft_check_null(parsing_data->argv[1]))
		return (0);
	while (parsing_data->argv[i])
	{
		if (parsing_data->argv[i] && !ft_strncmp(parsing_data->argv[i], \
		"-n", 2) && ft_validate_option(parsing_data->argv[i]))
			i++;
		else
			break ;
	}
	while (parsing_data->argv[i])
	{
		if (!ft_strcmp(parsing_data->argv[i], "$?"))
			printf("%d", g_exit_state);
		else
			printf("%s", parsing_data->argv[i]);
		i++;
		if (parsing_data->argv[i])
			printf(" ");
		else if (!parsing_data->argv[i] && (ft_strncmp(parsing_data->argv[1], \
					"-n", 2) || !ft_validate_option(parsing_data->argv[1])))
			printf("\n");
	}
	return (0);
}
