/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:10:27 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/10 14:11:53 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int    get_time(void)
{
    long int            time;
    struct timeval        current_time;

    time = 0;
    gettimeofday(&current_time, NULL);
    time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return (time);
}

void	ft_delay(unsigned long time)
{
	long	stop;

	stop = get_time() + time;
	time -= 10;
	time *= 1000;
	usleep(time);
	while (get_time() < stop)
		usleep(50);
}

long int	spent_time(long int time)
{
	int current_time;

	current_time = get_time() - time;
	return (current_time);
}
