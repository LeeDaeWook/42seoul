/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:40:02 by daewoole          #+#    #+#             */
/*   Updated: 2023/05/01 10:40:05 by daewoole         ###   ########.fr       */
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
