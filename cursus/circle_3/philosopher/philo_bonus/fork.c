#include "philosopher.h"

void	fork_process(t_philo *philo, int num_of_philo)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < num_of_philo)
	{
		pid = fork();
		philo[i].last_eat_time = get_time();
		if (pid < 0) // fork fail일 때 모든 프로세스를 종료시키는 것이 맞는가?
		{
			print_error("Error : fork failed", 1);
			kill_process(philo);
			exit(EXIT_FAILURE);
		}
		else if (!pid) // fork 함수의 반환값은 부모 프로세스에서는 child 프로세스의 pid, 자식 프로세스에서는 0이 반환된다.
			philosopher(philo + i);
		else if (pid)
			philo[i].pid = pid;
		i++;
	}
	is_finished(philo); // child process한테 신호를 보내줘야 함
	clear_semaphore(philo);
	free(philo);
}

void	kill_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->num_of_philo)
	{
		if (philo[i].pid)
			kill(philo[i].pid, SIGKILL);
		i++;
	}
}

void	is_finished(t_philo *philo)
{
	int	i;
	int	status;
	int	exit_status;

	i = 0;
	while (i < philo->args->num_of_philo)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status == IS_DIED)
			{
				kill_process(philo);
				return ;
			}
			else if (exit_status == IS_DONE_EATING)
			{
				(philo->args->num_of_finished)++;
				if (philo->args->num_of_finished == philo->args->num_of_philo)
					return ;
			}
		}
		i++;
	}
}
