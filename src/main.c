/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:49:17 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/11 13:03:16 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mess_arg(void)
{
	write(2, "Error args : nb of philos > 0, time (ms) to die,", 49);
	write(2, " eat, sleep and/or nb of times each philo must eat\n", 52);
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	if (5 > ac || ac > 6)
		return (mess_arg());
	if (!(data = parse_struct(&av[1])))
		return (1);
	if (!(philo = malloc_struct(data)))
		return (1);
	create_philo(data, philo);
	clear_all(data, philo);
	printf("AG\n");
}
