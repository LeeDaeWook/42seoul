#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>

typedef struct s_arg
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_arg;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	size_t			left;
	size_t			right;
}	t_philo;