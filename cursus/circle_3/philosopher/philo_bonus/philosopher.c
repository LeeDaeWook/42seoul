#include "philosopher.h"

void	*monitor_thread(void *philo)
{
	long long	now;
	t_philo		*philosopher;

	philosopher = (t_philo*)philo;
	while (!philosopher->is_died && !philosopher->is_done_eating)
	{
		now = get_time();
		if ((now - philosopher->last_eat_time) >= philosopher->args->time_to_die)
		{
			philosopher->is_died = 1;
			// print_state(philosopher, "died");
			break ;
		}
		if (philosopher->args->must_eat && philosopher->eat_times == philosopher->args->must_eat)
		{
			philosopher->is_done_eating = 1;
			break ;
		}
	}
	return (NULL);
}

void	philosopher(t_philo *philo) // 철학자들이 할 일을 수행하는 함수
{	
	pthread_t	thread;

	pthread_create(&thread, NULL, monitor_thread, philo);
	while (!philo->is_died && !philo->is_done_eating)
	{
		eating(philo);
		if (philo->args->must_eat && philo->eat_times == philo->args->must_eat)
			(philo->args->num_of_finished)++;
		sleeping(philo);
		thinking(philo);
	}
	pthread_join(thread, NULL);
	if (philo->is_died)
	{
		print_state(philo, "died");
		exit(IS_DIED);
	}
	else if (philo->is_done_eating)
		exit(IS_DONE_EATING);
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
	if (philo->is_died || philo->is_done_eating)
		return ;
	print_state(philo, "is sleeping");
	usleep(philo->args->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	if (philo->is_died || philo->is_done_eating)
		return ;
	print_state(philo, "is thinking");
}
