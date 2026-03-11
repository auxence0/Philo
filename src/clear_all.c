/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:53:12 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/11 16:26:38 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_all(t_data *data, t_philo *philo)
{
	if (data->fork)
		free(data->fork);
	if (data->lock_eat)
		free(data->lock_eat);
	if (data->lock_print)
		free(data->lock_print);
	if (data)
		free(data);
	if (philo)
		free(philo);
}

