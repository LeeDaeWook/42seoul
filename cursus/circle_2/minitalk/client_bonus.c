/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:13:09 by daewoole          #+#    #+#             */
/*   Updated: 2023/02/23 22:13:20 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

t_client	g_cli;

void	send_sig(int server_pid, char *message)
{
	static int	bit;
	static int	byte;
	int			temp;

	if (g_cli.connection == 0 && bit > 0)
		bit--;
	temp = (message[byte] >> (7 - bit)) & 1;
	if (temp == 0)
		kill(server_pid, SIGUSR1);
	else if (temp == 1)
		kill(server_pid, SIGUSR2);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		byte++;
	}
}

void	get_sig_client(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signal == SIGUSR1)
	{
		if (g_cli.connection == 0)
		{
			ft_printf("Client connected to Server\n");
			g_cli.connection = 1;
		}
		send_sig(g_cli.server_pid, g_cli.message);
		usleep(50);
	}
	else if (signal == SIGUSR2)
	{
		ft_printf("Signal transfer completed\n");
		exit(EXIT_SUCCESS);
	}
}

void	initializing_client(int argc, char *argv[], struct sigaction *sigac)
{
	if (argc != 3)
	{
		ft_printf("Wrong! Two parameters needed");
		exit(EXIT_FAILURE);
	}
	g_cli.server_pid = ft_atoi(argv[1]);
	g_cli.message = argv[2];
	sigac->sa_flags = SA_SIGINFO;
	sigemptyset(&(sigac->sa_mask));
	sigac->__sigaction_u.__sa_sigaction = get_sig_client;
}

void	initial_connect(void)
{
	if (g_cli.connection == 0)
	{
		while (g_cli.connection != 1)
		{
			send_sig(g_cli.server_pid, g_cli.message);
			usleep(10000);
		}
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sigac;

	initializing_client(argc, argv, &sigac);
	sigaction(SIGUSR1, &sigac, NULL);
	sigaction(SIGUSR2, &sigac, NULL);
	initial_connect();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
