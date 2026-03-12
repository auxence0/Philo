/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:25:54 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/12 11:41:27 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long	get_time_ms(void)
{
	struct	timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long long time_in_ms)
{
	long	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < time_in_ms)
		usleep(50);
}
