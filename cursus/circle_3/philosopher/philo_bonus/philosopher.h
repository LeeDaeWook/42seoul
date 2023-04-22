#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <semaphore.h>

# define FALSE 0
# define TRUE 1

# define IS_DIED 1
# define IS_DONE_EATING 2

typedef struct s_arg
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long long		start_time;
	int				num_of_finished;
	sem_t			*forks;
	sem_t			*done;
	sem_t			*print;
}	t_arg;

typedef struct s_philo
{
	t_arg		*args;
	size_t		id;
	int			eat_times;
	long long	last_eat_time;
	int			is_died;
	int			is_done_eating;
	pid_t		pid;
}	t_philo;

int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *s);
long long	get_time();
void		print_state(t_philo *philo, char *state);
void		custom_usleep(long long call_time, long long wait_time);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
int			print_error(char *error_message, int ret_val);
int			validate_arg(int argc, t_arg *args);
int			set_arg(int argc, char *argv[], t_arg *args);
t_philo		*set_philo(int num_of_philo, t_arg *args);
int			philosopher(t_philo *philo);
void		*monitor_thread(void *philo);
void		fork_process(t_philo *philo, int num_of_philo);
void		kill_process(t_philo *philo);
void		is_finished(t_philo *philo);
void		clear_semaphore(t_arg *args);

#endif