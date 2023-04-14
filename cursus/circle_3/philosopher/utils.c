#include "philosopher.h"

long	get_time()
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		// return (print_error("Error : get time failed", -1));
		return (-1);
	
	return (tv.tv_sec + tv.tv_usec);
}

void	print_state(t_philo *philo, char *state)
{
	long	now;

	now = get_time();
	if (now != -1)
	{
		pthread_mutex_lock(&(philo->args->print));
		printf("%ld %zd %s\n", now - philo->args->start_time, philo->id, state);
		if (!ft_strcmp(state, "is eating"))
			philo->args->last_eat_time = now - philo->args->start_time;
		pthread_mutex_unlock(&(philo->args->print));
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->forks[philo->left]));
	print_state(philo, "has taken a fork");
	if (philo->args->num_of_philo > 1)
	{
		pthread_mutex_lock(&(philo->args->forks[philo->right]));
		print_state(philo, "has taken a fork");
		print_state(philo, "is eating");
		usleep(philo->args->time_to_eat * 1000);
		pthread_mutex_unlock(&(philo->args->forks[philo->right]));
	}
	pthread_mutex_unlock(&(philo->args->forks[philo->left]));
}