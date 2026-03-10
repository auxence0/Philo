/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:22:24 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/10 10:39:49 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef	struct s_teh
{
	int				id;
	long int		*shared_counter;
	pthread_mutex_t	*mutex;
}		t_teh;


void	*routine(void *arg)
{
	t_teh	*teh = (t_teh *)arg;

	printf("Thread en cours d'execution %d\n", teh->id);
	int	i = 0;
	long int	*shared_count = teh->shared_counter;
	pthread_mutex_lock(teh->mutex);
	while (i++ < 1000000)
	{
		(*shared_count)++;
	}
	pthread_mutex_unlock(teh->mutex);
	free(teh);
	return (NULL);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pthread_t		thread[5];
	pthread_mutex_t	mutex;
	t_teh			*teh;
	int				i = 0;
	long int	counter = 0;

	pthread_mutex_init(&mutex, NULL);
	while (i < 5)
	{
		teh = malloc(sizeof(t_teh) * 1);
		teh->id = i;
		teh->mutex = &mutex;
		teh->shared_counter = &counter;
		pthread_create(&thread[i], NULL, routine, teh);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	printf("%ld\n", counter);
	pthread_mutex_destroy(&mutex);
	write(1, "Fin du main\n", 13);
}
