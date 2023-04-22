/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:01:14 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/22 18:01:17 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define FALSE 0
# define TRUE 1

typedef struct s_arg
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	int				is_finished;
	int				num_of_finished;
}	t_arg;

typedef struct s_philo
{
	t_arg			*args;
	pthread_t		thread;
	size_t			id;
	size_t			left;
	size_t			right;
	int				eat_times;
	long long		last_eat_time;
}	t_philo;

int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *s);
long long	get_time(void);
int			print_error(char *error_message, int ret_val);
void		print_state(t_philo *philo, char *state);
void		custom_usleep(long long call_time, long long wait_time);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		is_finished(t_philo *philo);
int			init_mutex(t_arg *args);
int			validate_arg(int argc, t_arg *args);
int			set_arg(int argc, char *argv[], t_arg *args);
t_philo		*set_philo(int num_of_philo, t_arg *args);
void		*philosopher(void *philo);
void		destroy_mutex(t_philo *philo);
void		thread(t_philo *philo, int num_of_philo);

#endif
