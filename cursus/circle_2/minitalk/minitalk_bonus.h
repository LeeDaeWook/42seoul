/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:34:26 by daewoole          #+#    #+#             */
/*   Updated: 2023/02/23 19:34:47 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_server
{
	int		client_pid;
	char	*message;
	int		byte;
}	t_server;

typedef struct s_client
{
	int		server_pid;
	char	*message;
	int		connection;
}	t_client;

void	finish_sig(siginfo_t *siginfo);
int		make_byte(char *c, int *bit, siginfo_t *siginfo);
void	get_sig_server(int signal, siginfo_t *siginfo, void *context);
void	initializing_server(struct sigaction *sigac);

void	send_sig(int server_pid, char *message);
void	get_sig_client(int signal, siginfo_t *siginfo, void *context);
void	initializing_client(int argc, char *argv[], struct sigaction *sigac);
void	initial_connect(void);

#endif
