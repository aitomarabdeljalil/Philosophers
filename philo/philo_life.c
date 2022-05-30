/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:31:26 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/14 20:23:45 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*plife(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(ph->info->time_die / 2);
	pthread_mutex_lock(&ph->mutex);
	while (ph->nbr_meals)
	{
		pthread_mutex_unlock(&ph->mutex);
		ft_takefork(ph);
		ft_eating(ph);
		ft_sleeping(ph);
		ft_thinking(ph);
		pthread_mutex_lock(&ph->mutex);
		if (ph->nbr_meals != -2)
			ph->nbr_meals--;
	}
	pthread_mutex_unlock(&ph->mutex);
	return (NULL);
}
