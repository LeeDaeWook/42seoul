/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:02:37 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/22 18:02:39 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (print_error("Error : get time failed", -1));
	return ((tv.tv_sec + (double)tv.tv_usec / 1000000) * 1000);
}

int	print_error(char *error_message, int ret_val)
{
	printf("%s\n", error_message);
	return (ret_val);
}

void	print_state(t_philo *philo, char *state)
{
	long long	now;

	now = get_time();
	if (now == -1)
		return ;
	sem_wait(philo->args->done);
	if (!ft_strcmp(state, "is eating"))
		philo->last_eat_time = now;
	if (philo->is_died || philo->is_done_eating)
	{
		sem_post(philo->args->done);
		return ;
	}
	sem_post(philo->args->done);
	sem_wait(philo->args->print);
	printf("%lldms %zd %s\n", \
	now - philo->args->start_time, philo->id, state);
	sem_post(philo->args->print);
}

void	custom_usleep(long long call_time, long long wait_time)
{
	long long	now;

	usleep(wait_time * 1000 * 0.8);
	while (TRUE)
	{
		now = get_time();
		if (now - call_time >= wait_time)
			return ;
		usleep(200);
	}
}

int	is_loop(t_philo *philo)
{
	int	flag;

	flag = 0;
	sem_wait(philo->args->done);
	if (philo->is_died || philo->is_done_eating)
		flag = 1;
	sem_post(philo->args->done);
	return (flag);
}
