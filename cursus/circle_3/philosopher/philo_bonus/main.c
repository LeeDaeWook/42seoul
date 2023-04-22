#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_arg	args;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (print_error("Error : Only 4 or 5 argument required", 1));
	if (set_arg(argc, argv, &args))
		return (print_error("Error : Invalid arguments", 1));
	philo = set_philo(args.num_of_philo, &args);
	if (!philo)
	{
		clear_semaphore(&args);
		return (print_error("Error : Memory allocation failed", 1));
	}
	fork_process(philo, args.num_of_philo);
	return (0);
}