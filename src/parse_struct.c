/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:31:33 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/18 13:46:57 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_arg(char *av, int min)
{
	int		status;
	long	nb;

	status = 0;
	nb = ft_atol(av, &status);
	if (status || nb < min || nb > 2147483647)
		return (-2);
	return (nb);
}

int	check_all_args(t_data *data)
{
	if (data->nb_philo == -2 || data->time_die == -2 || data->time_eat == -2
		|| data->time_sleep == -2 || data->iterate == -2)
	{
		mess_arg();
		if (data)
			free(data);
		data = NULL;
		return (0);
	}
	return (1);
}

t_data	*parse_struct(char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (err_mess("Error: Malloc Failed\n", data, NULL));
	memset(data, 0, sizeof(t_data));
	data->iterate = -1;
	data->finish_eat = -1;
	data->nb_philo = verif_arg(av[0], 1);
	data->time_die = verif_arg(av[1], 0);
	data->time_eat = verif_arg(av[2], 0);
	data->time_sleep = verif_arg(av[3], 0);
	if (av[4])
	{
		data->iterate = verif_arg(av[4], 0);
		data->finish_eat = 0;
	}
	if (!check_all_args(data))
		return (NULL);
	return (data);
}
