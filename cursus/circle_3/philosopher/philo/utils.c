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
		pthread_mutex_lock(&(philo->args->print));
		if (!philo->args->is_finished || !ft_strcmp(state, "died"))
			printf("%lldms %zd %s\n", now - philo->args->start_time, philo->id, state);
		if (!ft_strcmp(state, "is eating"))
			philo->last_eat_time = now;
		pthread_mutex_unlock(&(philo->args->print));
	}
}