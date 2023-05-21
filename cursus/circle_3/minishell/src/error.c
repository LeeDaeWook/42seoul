/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:06:50 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 23:10:07 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_defined_error(char *error_message, char *arg)
{
	write(STDERR_FILENO, error_message, ft_strlen(error_message));
	write(STDERR_FILENO, "\'", 1);
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, "\'", 1);
	write(STDERR_FILENO, "\n", 1);
	free(arg);
}

char	*ft_make_err_arg(char *arg)
{
	int		type;
	int		start;
	size_t	len;
	int		i;

	len = 2;
	i = 0;
	if (arg[i] == '<')
		type = IN;
	else
		type = OUT;
	i++;
	if ((arg[i] == '<' && type == IN) || (arg[i] == '>' && type == OUT))
		start = 2;
	else
		start = 1;
	if (type == IN)
		len = 3;
	return (ft_substr(arg, start, len));
}
