/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:49:17 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/16 16:13:00 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 4 && ac != 5)
	{
		write(2, "U need to give 3 or 4 arg : nb of philos, time to die,", 55);
		write(2, " eat, sleep and (nb of time each philo must eat)\n", 50);
		return (1);
	}
}
