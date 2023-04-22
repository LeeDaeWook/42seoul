/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:01:09 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/22 18:01:10 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher(void *philo)
{	
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	while (!philosopher->args->is_finished)
	{
		eating(philosopher);
		if (philosopher->args->must_eat && \
		philosopher->eat_times == philosopher->args->must_eat)
		{
			(philosopher->args->num_of_finished)++;
			break ;
		}
		sleeping(philosopher);
		thinking(philosopher);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2)
		pthread_mutex_lock(&(philo->args->forks[philo->left]));
	else
		pthread_mutex_lock(&(philo->args->forks[philo->right]));
	print_state(philo, "has taken a fork");
	if (philo->args->num_of_philo > 1)
	{
		if (philo->id % 2)
			pthread_mutex_lock(&(philo->args->forks[philo->right]));
		else
			pthread_mutex_lock(&(philo->args->forks[philo->left]));
		print_state(philo, "has taken a fork");
		print_state(philo, "is eating");
		custom_usleep(get_time(), philo->args->time_to_eat);
		philo->eat_times++;
		pthread_mutex_unlock(&(philo->args->forks[philo->right]));
	}
	pthread_mutex_unlock(&(philo->args->forks[philo->left]));
}

void	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
	custom_usleep(get_time(), philo->args->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
}
