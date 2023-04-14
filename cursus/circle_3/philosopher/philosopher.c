#include "philosopher.h"

int	print_error(char *error_message, int ret_val)
{
	printf("%s\n", error_message);
	return (ret_val);
}

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
	args->last_eat_time = args->start_time;
	if (args->start_time == -1)
		return (1);
	args->forks = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * args->num_of_philo);
	return (0);
}

int	set_philo(t_philo **philo, int num_of_philo, t_arg *args)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * num_of_philo);
	if (!philo)
		return (1);
	i = 0;
	while (i < num_of_philo)
	{
		(*philo)[i].args = args;
		(*philo)[i].id = i + 1;
		(*philo)[i].left = i + 1;
		(*philo)[i].right = (i + 1) % num_of_philo + 1;
		(*philo)[i].eat_times = 0;
		i++;
	}
	return (0);
}

void	*philosopher(void *philo) // 철학자들이 할 일을 수행하는 함수
{	
	t_philo	*philosopher;

	philosopher = (t_philo*)philo;
	while (!philosopher->args->is_died)
	{
		eating(philosopher);
		if (philosopher->eat_times == philosopher->args->must_eat)
			(philosopher->args->num_of_finished)++;
		sleeping(philosopher);
		thinking(philosopher);
	}
	return (NULL);
}

void	start_thread(t_philo *philo, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_create(&(philo[i].thread), NULL, philosopher, (void*)(philo + i));
		i++;
	}
	is_died(philo);
	i = 0;
	while (i < num_of_philo)
		pthread_join((philo[i++]).thread, NULL);
}

int	main(int argc, char *argv[])
{
	t_arg			args;
	t_philo			*philo;

	if (argc != 5 && argc != 6)
		return (print_error("Error : Argument count", 1));

	if (set_arg(argc, argv, &args))
		return (print_error("Error : Argument setting", 1));

	if (set_philo(&philo, args.num_of_philo, &args))
		return (print_error("Error : Memory allocation failed", 1));

	start_thread(philo, args.num_of_philo);

	return (0);
}