/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:01:01 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/22 18:01:02 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_arg			args;
	t_philo			*philo;

	if (argc != 5 && argc != 6)
		return (print_error("Error : Only 4 or 5 argument required", 1));
	if (set_arg(argc, argv, &args))
		return (print_error("Error : Invalid arguments", 1));
	philo = set_philo(args.num_of_philo, &args);
	if (!philo)
	{
		free(args.forks);
		return (print_error("Error : Memory allocation failed", 1));
	}
	thread(philo, args.num_of_philo);
	return (0);
}
