#include "philosopher.h"

long long	get_time()
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
	if (now != -1)
	{
		if (philo->is_died || philo->is_done_eating)
			return ;
		sem_wait(philo->args->print);
		printf("%lldms %zd %s\n", now - philo->args->start_time, philo->id, state);
		if (!ft_strcmp(state, "is eating"))
			philo->last_eat_time = now;
		sem_post(philo->args->print);
	}
}

void	clear_semaphore(t_philo *philo)
{
	if (sem_close(philo->args->forks) || sem_close(philo->args->done) || sem_close(philo->args->print))
	{
		print_error("closing semaphore failed", 1);
		exit(EXIT_FAILURE);
	}
	if (sem_unlink("sem_forks") || sem_unlink("sem_done") || sem_unlink("sem_print"))
	{
		print_error("closing semaphore failed", 1);
		exit(EXIT_FAILURE);
	}
}