#include "philosopher.h"

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
	free(philo->args->forks);
	free(philo);
}