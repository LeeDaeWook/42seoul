/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:25:19 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/03 19:08:56 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_num(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_exit_error(int flag)
{
	if (flag == NUMERIC_REQUIRED)
	{
		ft_putstr_fd("exit\nnumeric argument required\n", STDERR_FILENO);
		g_exit_state = 255;
		exit(255);
	}
	else if (flag == TOO_MANY_ARGUMENTS)
	{
		ft_putstr_fd("exit\ntoo many arguments\n", STDERR_FILENO);
		g_exit_state = 1;
	}
}

int	ft_validate_exit_arg(t_data *parsing_data, int *flag)
{
	int	i;

	if (parsing_data->argv[1] && !ft_is_num(parsing_data->argv[1]))
		*flag = NUMERIC_REQUIRED;
	i = 1;
	while (parsing_data->argv[i])
	{
		if (i >= 2 && *flag != NUMERIC_REQUIRED)
		{
			*flag = TOO_MANY_ARGUMENTS;
			break ;
		}
		i++;
	}
	return (*flag);
}

void	ft_malloc_exit(void)
{
	g_exit_state = errno;
	perror(NULL);
	exit(errno);
}

void	ft_exit(t_data *parsing_data)
{
	int	flag;

	flag = NONE_ERR;
	if (parsing_data && ft_validate_exit_arg(parsing_data, &flag))
		ft_exit_error(flag);
	else
	{
		printf("exit \n");
		if (parsing_data && parsing_data->argv[1])
		{
			flag = ft_atoi(parsing_data->argv[1]);
			g_exit_state = (unsigned char)flag;
		}
		else
			flag = EXIT_SUCCESS;
		exit(flag);
	}
}
