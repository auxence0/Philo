/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:11:22 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/18 11:52:10 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish_eat(t_philo *philo)
{
	int	status;

	status = 1;
	pthread_mutex_lock(&philo->data->lock_eat);
	if (philo->data->finish_eat == philo->data->nb_philo)
		status = 0;
	pthread_mutex_unlock(&philo->data->lock_eat);
	return (status);
}

int	check_goal_meal(t_philo *philo, int i)
{
	int	status;

	status = 1;
	pthread_mutex_lock(&philo->data->lock_eat);
	if (philo[i].nb_meal == philo->data->iterate)
		status = 0;
	pthread_mutex_unlock(&philo->data->lock_eat);
	return (status);
}

int	check_time_to_die(t_philo *philo, int i)
{
	int	status;

	status = 1;
	pthread_mutex_lock(&philo->data->lock_eat);
	if (philo[i].last_meal + philo->data->time_die <= get_time_ms())
	{
		philo->data->one_died = 1;
		status = 0;
	}
	pthread_mutex_unlock(&philo->data->lock_eat);
	return (status);
}

void	*monitoring(t_philo *philo)
{
	int	i;

	while (check_died(philo))
	{
		i = 0;
		if (!check_finish_eat(philo))
			return (NULL);
		while (i < philo->data->nb_philo)
		{
			if (!check_goal_meal(philo, i))
				break ;
			if (!check_time_to_die(philo, i))
				break ;
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
