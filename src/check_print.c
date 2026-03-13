/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:03:55 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/13 16:04:54 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_printf(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_print);
	if (!philo->data->one_died)
		printf("%ld %d %s", get_time_ms() - philo->data->start_time, philo->id,
			str);
	pthread_mutex_unlock(&philo->data->lock_print);
}
