#include "philosopher.h"

void	*philosopher(void *philo) // 철학자들이 할 일을 수행하는 함수
{	
	t_philo	*philosopher;

	philosopher = (t_philo*)philo;
	while (!philosopher->args->is_finished)
	{
		eating(philosopher);
		if (philosopher->args->must_eat && philosopher->eat_times == philosopher->args->must_eat)
			(philosopher->args->num_of_finished)++;
		sleeping(philosopher);
		thinking(philosopher);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	sem_wait(philo->args->forks);
	print_state(philo, "has taken a fork");
	if (philo->args->num_of_philo > 1)
	{
		sem_wait(philo->args->forks);
		print_state(philo, "has taken a fork");
		print_state(philo, "is eating");
		usleep(philo->args->time_to_eat * 1000);
		philo->eat_times++;
		sem_post(philo->args->forks);
	}
	sem_post(philo->args->forks);
}

void	sleeping(t_philo *philo)
{
	if (philo->args->is_finished)
		return ;
	print_state(philo, "is sleeping");
	usleep(philo->args->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	if (philo->args->is_finished)
		return ;
	print_state(philo, "is thinking");
}

void	is_finished(t_philo *philo)
{
	long long	now;
	int			i;

	while (!philo->args->is_finished)
	{
		i = 0;
		while (i < philo->args->num_of_philo)
		{
			now = get_time();
			if ((now - philo[i].last_eat_time) >= philo->args->time_to_die)
			{
				// philo->args->is_finished = 1;
				kill();
				print_state(philo + i, "died");
				break ;
			}
			i++;

		}
		if (philo->args->num_of_finished == philo->args->num_of_philo)
			philo->args->is_finished = 1;
	}
}
