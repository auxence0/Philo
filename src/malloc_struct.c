/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:46 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/17 16:40:42 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	malloc_struct(t_data *data, t_philo *philo)
{
	int	i;

	philo->philo = malloc(sizeof(int) * (data->nb_philo));
	philo->fork = malloc(sizeof(int) * (data->nb_philo));
	philo->eat = malloc(sizeof(int) * (data->time_eat));
	philo->sleep = malloc(sizeof(int) * (data->time_sleep));
	philo->think = malloc(sizeof(int) * (data->time_think));
	if (!philo->philo || !philo->fork || !philo->eat || !philo->sleep || !philo->think)
		err_mess("Error: malloc()\n", data, philo);
	i = 0;
	while (i < data->nb_philo)
	{
		philo->philo[i] = i;
		philo->fork[i] = 1;
		i++;
	}
}
