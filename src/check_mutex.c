/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:03:55 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/16 17:15:29 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_loop_philo(t_philo *philo)
{
	int	status;

	status = 1;
	pthread_mutex_lock(&philo->data->lock_eat);
	if (philo->nb_meal == philo->data->iterate || philo->data->one_died)
		status = 0;
	pthread_mutex_unlock(&philo->data->lock_eat);
	return (status);
}

int	check_died(t_philo *philo)
{
	int	status;

	status = 1;
	pthread_mutex_lock(&philo->data->lock_eat);
	if (philo->data->one_died)
		status = 0;
	pthread_mutex_unlock(&philo->data->lock_eat);
	return (status);
}

void	check_printf(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	if (check_died(philo))
		printf("%ld %d %s", get_time_ms() - philo->data->start_time, philo->id,
			str);
	pthread_mutex_unlock(&philo->data->lock_print);
}
