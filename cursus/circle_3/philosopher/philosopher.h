#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <errno.h>

# define false 0
# define true 1

# define EATING 1
# define SLEEPING 2
# define THINKING 3

typedef struct s_arg
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	last_eat_time;
	long	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_arg;

typedef struct s_philo
{
	t_arg			*args;
	int				state;
	pthread_t		thread;
	size_t			id;
	size_t			left;
	size_t			right;
}	t_philo;

#endif