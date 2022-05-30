/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:52:39 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/30 19:30:23 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_takefork(t_philo *ph)
{
	if (isdead(ph) == 1)
		return ;
	pthread_mutex_lock(ph->right);
	printf("%ld	[%d]	has taken a fork\n", spent_time(ph->start), ph->id);
	pthread_mutex_lock(&ph->left);
	printf("%ld	[%d]	has taken a fork\n", spent_time(ph->start), ph->id);
}

void	ft_eating(t_philo *ph)
{
	if (isdead(ph) == 1)
		return ;
	printf("%ld	[%d]	is eating\n", spent_time(ph->start), ph->id);
	ph->last_meal = get_time();
	ft_delay(ph->info->time_to_eat);
	pthread_mutex_unlock(ph->right);
	pthread_mutex_unlock(&ph->left);
}

void	ft_sleeping(t_philo *ph)
{
	if (isdead(ph) == 1)
		return ;
	printf("%ld	[%d]	is sleeping\n", spent_time(ph->start), ph->id);
	ft_delay(ph->info->time_sleep);
}

void	ft_thinking(t_philo *ph)
{
	if (isdead(ph) == 1)
		return ;
	printf("%ld	[%d]	is thinking\n", spent_time(ph->start), ph->id);
}
