/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:31:26 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/09 15:36:46 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*plife(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(ph->info->time_die / 2);
	while (!isdead(ph))
	{
		ft_takefork(ph);
		ft_eating(ph);
		ft_sleeping(ph);
		ft_thinking(ph);
	}
	return (NULL);
}
