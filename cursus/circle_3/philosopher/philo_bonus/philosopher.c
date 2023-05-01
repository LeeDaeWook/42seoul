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

void	philo_action(t_philo *philo)
{
	eating(philo);
	if (philo->args->num_of_philo > 1)
	{
		sleeping(philo);
		thinking(philo);
	}
	// else
	// 	custom_usleep(get_time(), 1);
}

int	philosopher(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, monitor_thread, philo);
	while (!is_loop(philo))
		philo_action(philo);
	pthread_join(thread, NULL);
	sem_wait(philo->args->done);
	if (philo->is_died)
	{
		printf("%lld %zd died\n", get_time() - \
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
	if (philo->args->num_of_philo <= 1)
		custom_usleep(get_time(), philo->args->time_to_die);
		// usleep(philo->args->time_to_die * 1000);
	// if (philo->args->num_of_philo > 1)
	else
	{
		sem_wait(philo->args->forks);
		print_state(philo, "has taken a fork");
		print_state(philo, "is eating");
		custom_usleep(get_time(), philo->args->time_to_eat);
		sem_wait(philo->args->done);
		if (philo->args->must_eat)
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
