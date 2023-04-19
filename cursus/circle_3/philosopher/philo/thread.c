#include "philosopher.h"

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->num_of_philo)
	{
		pthread_mutex_destroy(philo->args->forks + i);
		i++;
	}
	pthread_mutex_destroy(&(philo->args->print));
}

void	thread(t_philo *philo, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		philo[i].last_eat_time = get_time();
		pthread_create(&(philo[i].thread), NULL, philosopher, (philo + i));
		i++;
	}
	is_finished(philo);
	i = 0;
	while (i < num_of_philo)
		pthread_join((philo[i++]).thread, NULL);
	destroy_mutex(philo);
	free(philo->args->forks);
	free(philo);
}