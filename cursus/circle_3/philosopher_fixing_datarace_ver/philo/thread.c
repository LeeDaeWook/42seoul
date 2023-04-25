/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:01:31 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/22 18:01:32 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->num_of_philo)
	{
		pthread_mutex_destroy(philo->args->forks + i);
		i++;
	}
	pthread_mutex_destroy(&(philo->args->print));
	pthread_mutex_destroy(&(philo->args->finish));
	pthread_mutex_destroy(&(philo->args->time));
	pthread_mutex_destroy(&(philo->args->nof));
}

void	is_finished(t_philo *philo)
{
	long long	now;
	int			i;

	// while (!philo->args->is_finished)
	while (!temp(philo))
	{
		i = 0;
		while (!temp(philo) && i < philo->args->num_of_philo)
		{
			now = get_time();
			// pthread_mutex_lock(&(philo->args->time));
			if ((now - philo[i].last_eat_time) >= philo->args->time_to_die)
			{
				pthread_mutex_lock(&(philo->args->finish));
				philo->args->is_finished = 1;
				pthread_mutex_unlock(&(philo->args->finish));
				print_state(philo + i, "died");
				// break ;
				// pthread_mutex_unlock(&(philo->args->finish));
				// return ;
			}
			// pthread_mutex_unlock(&(philo->args->time));
			i++;
		}
		if (philo->args->num_of_finished == philo->args->num_of_philo)
		{
			pthread_mutex_lock(&(philo->args->finish));
			philo->args->is_finished = 1;
			pthread_mutex_unlock(&(philo->args->finish));
			printf("All philosophers have eaten enough\n");
			// break;
		}
	}
}

void	thread(t_philo *philo, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		philo[i].last_eat_time = get_time();
		pthread_create(&(philo[i].thread), NULL, philosopher, (philo + i));
		i++;
	}
	is_finished(philo);
	i = 0;
	while (i < num_of_philo)
		pthread_join((philo[i++]).thread, NULL);
	destroy_mutex(philo);
	free(philo->args->forks);
	free(philo);
}
