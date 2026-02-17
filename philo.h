/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:50:26 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/17 16:58:36 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_data			*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				iterate;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*lock;
}					t_data;

long	ft_atol(const char *nptr, int *status);
int		check_arg(char **av, t_data *data);
void	malloc_struct(t_data *data, t_philo *philo);
void	err_mess(char *mess, t_data *data, t_philo *philo);
void	ft_putstr_fd(char *s, int fd);
void	clear_all(t_data *data, t_philo *philo);
void	create_philo(t_data *data, t_philo *philo);

#endif