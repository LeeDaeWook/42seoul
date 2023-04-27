/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:02:31 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/22 18:02:32 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
	sem_unlink("sem_forks");
	sem_unlink("sem_done");
	sem_unlink("sem_print");
	args->forks = sem_open("sem_forks", O_CREAT, 0644, args->num_of_philo);
	args->done = sem_open("sem_done", O_CREAT, 0644, 1);
	args->print = sem_open("sem_print", O_CREAT, 0644, 1);
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
		memset(&philo[i], 0, sizeof(t_philo));
		philo[i].args = args;
		philo[i].id = i + 1;
		i++;
	}
	return (philo);
}
