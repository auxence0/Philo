/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:31:33 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/17 14:33:25 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **av, t_data *data)
{
	int		i;
	int		status;
	int		check_atol;

	check_atol = 0;
	status = 0;
	i = 0;
	data->nb_philo = ft_atol(av[i++], &check_atol);
	status |= (data->nb_philo < 1 || data->nb_philo > INT_MAX || check_atol);
	data->time_die = ft_atol(av[i++], &check_atol);
	status |= (data->time_die < 0 || data->time_die > INT_MAX || check_atol);
	data->time_eat = ft_atol(av[i++], &check_atol);
	status |= (data->time_eat < 0 || data->time_die > INT_MAX || check_atol);
	data->time_sleep = ft_atol(av[i++], &check_atol);
	status |= (data->time_sleep < 0 || data->time_sleep > INT_MAX || check_atol);
	if (av[i])
	{
		data->iterate = ft_atol(av[i], &check_atol);
		status |= (data->iterate < 0 || data->iterate > INT_MAX || check_atol);
	}
	return (status);
}
