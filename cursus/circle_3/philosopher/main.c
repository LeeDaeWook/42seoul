#include "philosopher.h"

int	print_error(char *error_message, int ret_val)
{
	printf("%s\n", error_message);
	return (ret_val);
}

void	set_arg(char *argv[], t_arg *args)
{
	args->num_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
}

// *errno = pthread_create(&thread, NULL, );

void	set_philo(t_philo **philo, size_t num_of_philo, int *errno)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * num_of_philo);
	i = 1;
	while (i <= num_of_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % num_of_philo;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pthread_mutex_t	mutex;
	t_arg			args;
	t_philo			*philo;
	int				errno;

	if (argc != 5)
		return (print_error("Only 4 arguments needed!", 1));
	
	set_arg(argv, &args);
	if (args.num_of_philo <= 1) // 철학자가 1명일 때는, 포크도 1개여서 식사 불가능 -> error처리
		// error처리

	set_philo(&philo, args.num_of_philo, &errno);

	return (0);
}