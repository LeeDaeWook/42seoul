/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:13:36 by daewoole          #+#    #+#             */
/*   Updated: 2023/02/23 22:13:49 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

t_server	g_ser;

void	finish_sig(siginfo_t *siginfo)
{
	int	close_flag;

	close_flag = 0;
	if (ft_strcmp(g_ser.message + (ft_strlen(g_ser.message) - g_ser.byte), \
				"close server") == 0)
		close_flag = 1;
	ft_printf("%s\n", g_ser.message + (ft_strlen(g_ser.message) - g_ser.byte));
	free(g_ser.message);
	kill(siginfo->si_pid, SIGUSR2);
	if (close_flag)
		exit(EXIT_SUCCESS);
	g_ser.client_pid = 0;
	g_ser.byte = 0;
	g_ser.message = 0;
	g_ser.message = (char *)malloc(sizeof(char));
	if (!g_ser.message)
	{
		ft_printf("memory allocation failure!\n");
		exit(EXIT_FAILURE);
	}
	*g_ser.message = '\0';
}

int	make_byte(char *c, int *bit, siginfo_t *siginfo)
{
	char	*temp;

	temp = g_ser.message;
	g_ser.message = ft_strjoin(g_ser.message, c);
	free(temp);
	*bit = 0;
	if (*c == '\0')
	{
		finish_sig(siginfo);
		return (1);
	}
	g_ser.byte++;
	*c = 0;
	return (0);
}

void	get_sig_server(int signal, siginfo_t *siginfo, void *context)
{
	static int	bit;
	static char	c;

	(void)context;
	if (g_ser.client_pid == 0)
		g_ser.client_pid = siginfo->si_pid;
	if (siginfo->si_pid != g_ser.client_pid)
		return ;
	if (signal == SIGUSR1)
		c |= 0 << (7 - bit);
	else if (signal == SIGUSR2)
		c |= 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		if (make_byte(&c, &bit, siginfo) == 1)
			return ;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

void	initializing_server(struct sigaction *sigac)
{
	sigac->sa_flags = SA_SIGINFO;
	sigemptyset(&(sigac->sa_mask));
	sigac->__sigaction_u.__sa_sigaction = get_sig_server;
	g_ser.message = (char *)malloc(sizeof(char));
	if (!g_ser.message)
	{
		ft_printf("memory allocation failure!\n");
		exit(EXIT_FAILURE);
	}
	*g_ser.message = '\0';
}

int	main(void)
{
	struct sigaction	sigac;

	ft_printf("Server PID: %d\n", getpid());
	initializing_server(&sigac);
	sigaction(SIGUSR1, &sigac, NULL);
	sigaction(SIGUSR2, &sigac, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
