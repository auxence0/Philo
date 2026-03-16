/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:50:26 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:41 by asauvage         ###   ########.fr       */
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

typedef struct s_data
{
	int				nb_philo;
	int				finish_eat;
	int				iterate;
	long			start_time;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				one_died;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_eat;
}					t_data;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				nb_meal;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_data			*data;
}					t_philo;

t_data		*parse_struct(char **av);
long		ft_atol(const char *nptr, int *status);
int			mess_arg(void);
t_philo		*malloc_struct(t_data *data);
void		*err_mess(char *mess, t_data *data, t_philo *philo);
void		ft_putstr_fd(char *s, int fd);
void		clear_all(t_data *data, t_philo *philo);
void		create_philo(t_data *data, t_philo *philo);
void		ft_usleep(long time_in_ms);
long		get_time_ms(void);
void		check_printf(char *str, t_philo *philo);
void		*monitoring(t_philo *philo);

#endif