/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:49:17 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/18 13:45:59 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mess_arg(void)
{
	write(2, "Error: Usage: ./philo <nb_philos> <time_die> <time_eat>", 56);
	write(2, " <time_sleep> [nb_meals]\n", 26);
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	if (5 > ac || ac > 6)
		return (mess_arg());
	data = parse_struct(&av[1]);
	if (!data)
		return (1);
	philo = malloc_struct(data);
	if (!philo)
		return (1);
	create_philo(data, philo);
	clear_all(data, philo);
	return (0);
}
