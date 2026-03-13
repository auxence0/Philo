/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:46 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/13 16:05:25 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*malloc_struct(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * (data->nb_philo));
	if (!philo)
		return (err_mess("Error : Malloc failed\n", data, philo));
	data->fork = malloc(sizeof(pthread_mutex_t) * (data->nb_philo));
	if (!data->fork)
		return (err_mess("Error : Malloc failed\n", data, philo));
	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].l_fork = &data->fork[i];
		philo[i].r_fork = &data->fork[(i + 1) % data->nb_philo];
		pthread_mutex_init(&data->fork[i], NULL);
		philo[i].data = data;
		philo[i].last_meal = get_time_ms();
		philo[i].nb_meal = 0;
		i++;
	}
	philo->data = data;
	return (philo);
}
