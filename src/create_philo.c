/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:12 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/17 16:40:07 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	int id;

	id = *(int *)arg;
	printf("id num : %d\n", id);
	return (NULL);
}

void	create_philo(t_data *data, t_philo *philo)
{
	int			i;
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * (data->nb_philo));
	if (!thread)
		err_mess("Error: malloc\n", data, philo);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&thread[i], NULL, routine, &philo->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
