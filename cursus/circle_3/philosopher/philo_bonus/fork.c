/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:01:51 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/22 18:01:53 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	fork_process(t_philo *philo, int num_of_philo)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < num_of_philo)
	{
		pid = fork();
		philo[i].last_eat_time = get_time();
		if (pid < 0)
		{
			print_error("Error : fork failed", 1);
			kill_process(philo);
			exit(EXIT_FAILURE);
		}
		else if (!pid)
			philosopher(philo + i);
		else if (pid)
			philo[i].pid = pid;
		i++;
	}
	is_finished(philo);
	clear_semaphore(philo->args);
	free(philo);
}

void	kill_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->num_of_philo)
	{
		if (philo[i].pid)
			kill(philo[i].pid, SIGKILL);
		i++;
	}
}

void	is_finished(t_philo *philo)
{
	int	i;
	int	status;
	int	exit_status;

	i = 0;
	while (i++ < philo->args->num_of_philo)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status == IS_DIED)
			{
				kill_process(philo);
				return ;
			}
			else if (exit_status == IS_DONE_EATING)
			{
				(philo->args->num_of_finished)++;
				if (philo->args->num_of_finished == philo->args->num_of_philo)
					printf("All philosophers have eaten enough\n");
			}
		}
	}
}
