/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:53:12 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/17 14:54:09 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_all(t_data *data, t_philo *philo)
{
	if (philo->philo)
		free(philo->philo);
	if (philo->fork)
		free(philo->fork);
	if (philo->eat)
		free(philo->eat);
	if (philo->sleep);
		free(philo->sleep);
	if (philo->think)
		free(philo->think);
}
