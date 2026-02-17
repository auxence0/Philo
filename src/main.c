/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:49:17 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/17 16:04:34 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mess_arg(void)
{
	write(2, "Error : args -> nb of philos > 0, time (ms) to die,", 52);
	write(2, " eat, sleep and/or nb of times each philo must eat\n", 52);
	exit (1);
}

int	main(int ac, char **av)
{
	t_philo	philo;
	t_data	data;

	memset(&philo, 0, sizeof(t_philo));
	memset(&data, 0, sizeof(t_data));
	if (5 >	 ac || ac > 6 || check_arg(&av[1], &data))
		mess_arg();
	malloc_struct(&data, &philo);
	create_philo(&data, &philo);
}
