/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:12 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/13 16:04:52 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitoring(t_philo *philo)
{
	int	i;

	while (!philo->data->one_died)
	{
		i = 0;
		if (philo->data->finish_eat == philo->data->nb_philo)
			return (NULL);
		while (i < philo->data->nb_philo)
		{
			if (philo[i].nb_meal == philo->data->iterate)
				break ;
			if (philo[i].last_meal + philo->data->time_die <= get_time_ms())
			{
				philo->data->one_died = 1;
				break ;
			}
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

void	eat(t_philo *philo)
{
	philo->nb_meal += 1;
	philo->last_meal = get_time_ms();
	check_printf("is eating\n", philo);
	ft_usleep(philo->data->time_eat);
}

void	even_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	check_printf("has taken a fork\n", philo);
	pthread_mutex_lock(philo->l_fork);
	check_printf("has taken a fork\n", philo);
}

void	odd_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	check_printf("has taken a fork\n", philo);
	pthread_mutex_lock(philo->r_fork);
	check_printf("has taken a fork\n", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philo == 1)
	{
		check_printf("has taken a fork\n", philo);
		return (NULL);
	}
	if (philo->id % 2)
		ft_usleep(5);
	while (philo->nb_meal != philo->data->iterate && !philo->data->one_died)
	{
		if (philo->id % 2)
			even_philo(philo);
		else
			odd_philo(philo);
		eat(philo);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		if (!philo->data->one_died && philo->nb_meal <= philo->data->iterate)
		{
			check_printf("is sleeping\n", philo);
			ft_usleep(philo->data->time_sleep);
			if (philo->data->one_died)
				break ;
			check_printf("is thinking\n", philo);
			if (philo->data->nb_philo % 2 && philo->data->time_eat * 2
				- philo->data->time_sleep > 0)
				ft_usleep(philo->data->time_eat * 2 - philo->data->time_sleep);
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

	i = 0;
	philo->data->start_time = get_time_ms();
	pthread_mutex_init(&data->lock_eat, NULL);
	pthread_mutex_init(&data->lock_print, NULL);
	while (i < data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	monitoring(philo);
	pthread_mutex_destroy(&philo->data->lock_eat);
	pthread_mutex_destroy(&philo->data->lock_print);
	i = 0;
	while (i < philo->data->nb_philo)
		pthread_mutex_destroy(philo[i++].l_fork);
}
