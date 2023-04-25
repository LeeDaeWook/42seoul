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

int	temp(t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&(philo->args->finish));
	if (philo->args->is_finished)
		flag = 1;
	pthread_mutex_unlock(&(philo->args->finish));
	return (flag);
}

void	*philosopher(void *philo)
{	
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	// if (!(philosopher->id % 2))
	// 	usleep(500);
	while (!temp(philosopher))
	{
		eating(philosopher);
		if (philosopher->args->must_eat && \
		philosopher->eat_times == philosopher->args->must_eat)
		{
			pthread_mutex_lock(&(philosopher->args->finish));
			(philosopher->args->num_of_finished)++;
			pthread_mutex_unlock(&(philosopher->args->finish));
			break ;
		}
		sleeping(philosopher);
		thinking(philosopher);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	if (!(philo->id % 2))
		pthread_mutex_lock(&(philo->args->forks[philo->left]));
	else
		pthread_mutex_lock(&(philo->args->forks[philo->right]));
	print_state(philo, "has taken a fork");
	if (philo->args->num_of_philo > 1)
	{
		if (!(philo->id % 2))
			pthread_mutex_lock(&(philo->args->forks[philo->right]));
		else
			pthread_mutex_lock(&(philo->args->forks[philo->left]));
		print_state(philo, "has taken a fork");
		print_state(philo, "is eating");
		custom_usleep(get_time(), philo->args->time_to_eat);
		philo->eat_times++;
		if (!(philo->id % 2))
			pthread_mutex_unlock(&(philo->args->forks[philo->left]));
		else
			pthread_mutex_unlock(&(philo->args->forks[philo->right]));
	}
	if (!(philo->id % 2))
		pthread_mutex_unlock(&(philo->args->forks[philo->right]));
	else
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
