/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:12 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/11 16:33:20 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitoring(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		while (i < philo->data->nb_philo)
		{
			if (philo[i].nb_meal == philo->data->iterate)
				break ;
			if (philo[i].last_meal - philo->data->time_die > get_time_ms())
				break ;
			i++;
		}
		i = 0;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	philo = (t_philo *)arg;
	philo->data->start_time = get_time_ms();
	while (philo->nb_meal != philo->data->iterate && !philo->data->one_died)
	{
		if (philo->id % 2)
		{
			pthread_mutex_lock(philo->l_fork);
			pthread_mutex_lock(philo->r_fork);
			ft_usleep(philo->data->time_eat);
			pthread_mutex_lock(&philo->data->lock_eat);
			philo->nb_meal += 1;
			philo->last_meal = get_time_ms();
			pthread_mutex_unlock(&philo->data->lock_eat);
			pthread_mutex_lock(&philo->data->lock_print);
			if (!philo->data->one_died)
				printf("Philo %d is eating\n", philo->id);
			pthread_mutex_unlock(&philo->data->lock_print);
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			if (!philo->data->one_died)
				printf("Philo %d is sleeping\n", philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->r_fork);
			pthread_mutex_lock(philo->l_fork);
			ft_usleep(philo->data->time_eat);
			pthread_mutex_lock(&philo->data->lock_eat);
			philo->nb_meal += 1;
			philo->last_meal = get_time_ms();
			pthread_mutex_unlock(&philo->data->lock_eat);
			pthread_mutex_lock(&philo->data->lock_print);
			if (!philo->data->one_died)
				printf("Philo %d is eating\n", philo->id);
			pthread_mutex_unlock(&philo->data->lock_print);
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			if (!philo->data->one_died)
				printf("Philo %d is sleeping\n", philo->id);
		}
	}
	return (NULL);
}

void	create_philo(t_data *data, t_philo *philo)
{
	int	i;
	pthread_t	thread_monitoring;

	i = 0;
	pthread_mutex_init(&data->lock_eat, NULL);
	pthread_mutex_init(&data->lock_print, NULL);
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	pthread_create(&thread_monitoring, NULL, monitoring, &philo);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(thread_monitoring, NULL);
}
