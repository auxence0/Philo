/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_mess.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:46 by asauvage          #+#    #+#             */
/*   Updated: 2026/03/17 14:41:04 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	*err_mess(char *mess, t_data *data, t_philo *philo)
{
	int	len;

	len = ft_strlen(mess);
	clear_all(data, philo);
	write(2, mess, len);
	return (NULL);
}
