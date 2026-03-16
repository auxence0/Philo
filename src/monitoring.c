/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:11:22 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/16 11:58:48 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitoring(t_philo *philo)
{
	int	i;

	while (!philo->data->one_died)
	{
		i = 0;
		pthread_mutex_lock(&philo->data->lock_eat);
		if (philo->data->finish_eat == philo->data->nb_philo)
		{
			pthread_mutex_unlock(&philo->data->lock_eat);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->lock_eat);
		while (i < philo->data->nb_philo)
		{
			pthread_mutex_lock(&philo->data->lock_eat);
			if (philo[i].nb_meal == philo->data->iterate)
			{
				pthread_mutex_unlock(&philo->data->lock_eat);
				break ;
			}
			if (philo[i].last_meal + philo->data->time_die <= get_time_ms())
			{
				philo->data->one_died = 1;
				pthread_mutex_unlock(&philo->data->lock_eat);
				break ;
			}
			pthread_mutex_unlock(&philo->data->lock_eat);
			i++;
		}
		usleep(500);
	}
	pthread_mutex_lock(&philo->data->lock_print);
	printf("%ld %d died\n", get_time_ms() - philo->data->start_time,
		philo[i].id);
	pthread_mutex_unlock(&philo->data->lock_print);
	return (NULL);
}
