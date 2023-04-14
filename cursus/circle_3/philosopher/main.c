#include "philosopher.h"

int	print_error(char *error_message, int ret_val)
{
	printf("%s\n", error_message);
	return (ret_val);
}

int	set_arg(int argc, char *argv[], t_arg *args)
{
	args->num_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	args->start_time = get_time();
	if (args->start_time == -1)
		return (1);
	args->forks = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * args->num_of_philo);
	return (0);
}

int	set_philo(t_philo **philo, size_t num_of_philo, t_arg *args)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * num_of_philo);
	if (!philo)
		return (1);
	i = 0;
	while (i < num_of_philo)
	{
		(*philo)[i].args = args;
		(*philo)[i].state = THINKING;
		(*philo)[i].id = i + 1;
		(*philo)[i].left = i + 1;
		(*philo)[i].right = (i + 1) % num_of_philo + 1;
		i++;
	}
	return (0);
}

void	philosopher(void *philo) // 철학자들이 할 일을 수행하는 함수
{
	philo = (t_philo*)philo;

	while (true)
	{
		eating(philo);
		sleeping();
		thinking();
	}
}

void	start_thread(t_philo *philo, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_create(philo[i].thread, NULL, philosopher, (void*)(philo + i));
		i++;
	}
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