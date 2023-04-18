#include "philosopher.h"

int	set_arg(int argc, char *argv[], t_arg *args)
{
	memset(args, 0, sizeof(t_arg));
	args->num_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (args->num_of_philo <= 0 || args->time_to_die < 0 \
	|| args->time_to_eat < 0 || args->time_to_sleep < 0)
		return (1);
	if (argc == 6)
	{
		args->must_eat = ft_atoi(argv[5]);
		if (args->must_eat <= 0)
			return (1);
	}
	args->start_time = get_time();
	if (args->start_time == -1)
		return (1);
	args->forks = (sem_t*)malloc(sizeof(sem_t) * args->num_of_philo);
	if (!args->forks)
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
		philo[i].eat_times = 0;
		i++;
	}
	return (philo);
}