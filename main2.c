/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:47:58 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/10 18:06:37 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef	struct s_teh
{
	pthread_mutex_t	*mutex_stop;
	int				stop_flag;
}					t_teh;

long long	get_time_ms(void)
{
	struct	timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long long time_in_ms)
{
	long long	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < time_in_ms)
		usleep(50);
}


int	main(void)
{
	long long start = get_time_ms();
	ft_usleep(200);
	long long end = get_time_ms();
	printf("Temps ecoule : %lld ms\n", end - start);
}
