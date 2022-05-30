/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdead.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:31:39 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/30 19:30:42 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isdead(t_philo *ph)
{
	long	last_meal;

	pthread_mutex_lock(&ph->mutex);
	last_meal = ph->last_meal;
	pthread_mutex_unlock(&ph->mutex);
	if (get_time() - last_meal > ph->info->time_die)
	{
		pthread_mutex_lock(&ph->info->death_mutex);
		if (ph->info->death_index == -1)
		{
			ph->info->death_index = ph->id;
			ph->info->death_time = get_time();
		}
		pthread_mutex_unlock(&ph->info->death_mutex);
		return (1);
	}
	return (0);
}

int	is_someone_dead(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].info->nbr_philo)
	{
		if (isdead(ph + i))
			return (true);
		i++;
	}
	return (false);
}

int	is_someone_eating(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].info->nbr_philo)
	{
		pthread_mutex_lock(&ph->mutex);
		if (ph[i].nbr_meals == -2 || ph[i].nbr_meals > 0)
		{
			pthread_mutex_unlock(&ph->mutex);
			return (true);
		}
		pthread_mutex_unlock(&ph->mutex);
		i++;
	}
	return (false);
}

void	main_check(t_philo *ph)
{
	while (is_someone_eating(ph))
	{
		if (is_someone_dead(ph))
		{
			printf("%ld	[%d]	is dead\n", spent_time(ph->start),
				ph->info->death_index);
			return ;
		}
		usleep(100);
	}
}
