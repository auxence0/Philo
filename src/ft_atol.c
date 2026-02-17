/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:16:37 by asauvage          #+#    #+#             */
/*   Updated: 2026/02/17 14:21:21 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	skip_spaces(const char *nptr, int i)
{
	while (nptr[i] == ' ' || ('\t' <= nptr[i] && nptr[i] <= '\r'))
		i++;
	return (i);
}

long	ft_atol(const char *nptr, int *status)
{
	long	nb;
	int		i;
	int		m;

	i = 0;
	m = 1;
	nb = 0;
	if (!nptr)
	i = skip_spaces(nptr, i);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			m = m * -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		if (nb > 2147483648)
			break ;
		i++;
	}
	i = skip_spaces(nptr, i);
	*status = nptr[i];
	return (m * nb);
}
