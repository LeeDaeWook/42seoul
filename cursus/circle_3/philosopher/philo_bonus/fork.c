#include "philosopher.h"

void	fork_process(t_philo *philo, int num_of_philo)
{
	int	i;
	pid_t	pid;

	i = 0;
	while (i < num_of_philo)
	{
		pid = fork();
		if (!pid) // fork 함수의 반환값은 부모 프로세스에서는 child 프로세스의 pid, 자식 프로세스에서는 0이 반환된다.
		{
			philo[i].last_eat_time = get_time();
			philosopher(philo + i);
			exit(0);
		}
		i++;
	}
	is_finished(philo); // child process한테 신호를 보내줘야 함

	free(philo);
}