/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdead.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:31:39 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/11 12:15:21 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isdead(t_philo *ph)
{
	if (ph->info->nbr_pilo_eat > 0)
		if (ph->nbr_meals == ph->info->nbr_pilo_eat)
			return (1);
	pthread_mutex_lock(&ph->dead);
	if (spent_time(ph->start) - ph->last_meal > ph->info->time_die)
	{
		if (i == 0)
		{
			i = -1;
			printf("%ld	[%d]	died\n", spent_time(ph->start), ph->id);
		}
		pthread_mutex_unlock(&ph->dead);
		return (-1);
	}
	pthread_mutex_unlock(&ph->dead);
	return (0);
}

pprintf(){
	pthread_mutex_lock
	if (ph.inf.iddead == -1)
	{
		printf
		return true
	}
	else
		reutnr false;
	pthread_mutex_unlock
}