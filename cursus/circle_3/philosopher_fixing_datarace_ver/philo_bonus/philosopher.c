/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:02:19 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/22 18:02:21 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*monitor_thread(void *philo)
{
	long long	now;
	t_philo		*philosopher;

	philosopher = (t_philo *)philo;
	while (!is_loop(philosopher))
	{
		sem_wait(philosopher->args->done);
		now = get_time();
		if ((now - philosopher->last_eat_time) >= \
		philosopher->args->time_to_die)
		{
			philosopher->is_died = 1;
			sem_post(philosopher->args->done);
			break ;
		}
		if (philosopher->args->must_eat && \
		philosopher->eat_times == philosopher->args->must_eat)
			philosopher->is_done_eating = 1;
		sem_post(philosopher->args->done);
	}
	return (NULL);
}

int	philosopher(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, monitor_thread, philo);
	while (!is_loop(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	pthread_join(thread, NULL);
	sem_wait(philo->args->done);
	if (philo->is_died)
	{
		printf("%lldms %zd died\n", get_time() - \
		philo->args->start_time, philo->id);
		exit(IS_DIED);
	}
	else if (philo->is_done_eating)
	{
		sem_post(philo->args->done);
		exit(IS_DONE_EATING);
	}
	sem_post(philo->args->done);
	return (0);
}

void	eating(t_philo *philo)
{
	if (is_loop(philo))
		return ;
	sem_wait(philo->args->forks);
	print_state(philo, "has taken a fork");
	if (philo->args->num_of_philo > 1)
	{
		sem_wait(philo->args->forks);
		print_state(philo, "has taken a fork");
		print_state(philo, "is eating");
		custom_usleep(get_time(), philo->args->time_to_eat);
		sem_wait(philo->args->done);
		philo->eat_times++;
		sem_post(philo->args->done);
		sem_post(philo->args->forks);
	}
	sem_post(philo->args->forks);
}

void	sleeping(t_philo *philo)
{
	if (is_loop(philo))
		return ;
	print_state(philo, "is sleeping");
	custom_usleep(get_time(), philo->args->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	if (is_loop(philo))
		return ;
	print_state(philo, "is thinking");
}
