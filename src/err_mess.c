/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_mess.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:46 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/17 14:56:06 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_mess(char *mess, t_data *data, t_philo *philo)
{
	clear_all(data, philo);
	ft_putstr_fd(mess, 2);
	exit (1);
}
