/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:01:23 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/22 18:01:25 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_mutex(t_arg *args)
{
	int	i;

	i = 0;
	while (i < args->num_of_philo)
	{
		if (pthread_mutex_init((args->forks + i), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(args->print), NULL))
		return (1);
	return (0);
}

int	validate_arg(int argc, t_arg *args)
{
	if (args->num_of_philo <= 0 || args->time_to_die < 0 \
	|| args->time_to_eat < 0 || args->time_to_sleep < 0)
		return (0);
	if (argc == 6 && args->must_eat <= 0)
		return (0);
	return (1);
}

int	set_arg(int argc, char *argv[], t_arg *args)
{
	memset(args, 0, sizeof(t_arg));
	args->num_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->must_eat = ft_atoi(argv[5]);
	if (!validate_arg(argc, args))
		return (1);
	args->start_time = get_time();
	if (args->start_time == -1)
		return (1);
	args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	args->num_of_philo);
	if (!args->forks)
		return (1);
	if (init_mutex(args))
		return (1);
	return (0);
}

t_philo	*set_philo(int num_of_philo, t_arg *args)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * num_of_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < num_of_philo)
	{
		philo[i].args = args;
		philo[i].id = i + 1;
		philo[i].left = i + 1;
		philo[i].right = (i + 1) % num_of_philo + 1;
		philo[i].eat_times = 0;
		i++;
	}
	return (philo);
}
