/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:12 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/18 10:57:51 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_eat);
	philo->nb_meal += 1;
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->data->lock_eat);
	check_printf("is eating\n", philo);
	ft_usleep(philo->data->time_eat, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	even_or_odd_philo(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->r_fork);
		check_printf("has taken a fork\n", philo);
		pthread_mutex_lock(philo->l_fork);
		check_printf("has taken a fork\n", philo);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		check_printf("has taken a fork\n", philo);
		pthread_mutex_lock(philo->r_fork);
		check_printf("has taken a fork\n", philo);
	}
}

int	sleep_and_thinking(t_philo *philo)
{
	check_printf("is sleeping\n", philo);
	ft_usleep(philo->data->time_sleep, philo);
	if (!check_died(philo))
		return (0);
	check_printf("is thinking\n", philo);
	if (philo->data->nb_philo % 2 && philo->data->time_eat * 2
		- philo->data->time_sleep > 0)
		ft_usleep(philo->data->time_eat * 2 - philo->data->time_sleep, philo);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philo == 1 && philo->data->iterate != 0)
	{
		check_printf("has taken a fork\n", philo);
		return (NULL);
	}
	if (philo->id % 2)
		ft_usleep(5, philo);
	while (check_loop_philo(philo))
	{
		even_or_odd_philo(philo);
		eat(philo);
		if (check_died(philo))
		{
			if (!sleep_and_thinking(philo))
				break ;
		}
	}
	pthread_mutex_lock(&philo->data->lock_eat);
	if (philo->nb_meal == philo->data->iterate)
		philo->data->finish_eat += 1;
	pthread_mutex_unlock(&philo->data->lock_eat);
	return (NULL);
}

void	create_philo(t_data *data, t_philo *philo)
{
	int	i;

	philo->data->start_time = get_time_ms();
	pthread_mutex_init(&data->lock_eat, NULL);
	pthread_mutex_init(&data->lock_print, NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	monitoring(philo);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&philo->data->lock_eat);
	pthread_mutex_destroy(&philo->data->lock_print);
	i = 0;
	while (i < philo->data->nb_philo)
		pthread_mutex_destroy(philo[i++].l_fork);
}
