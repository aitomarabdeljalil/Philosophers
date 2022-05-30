/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:10:27 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/30 13:19:02 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	get_time(void)
{
	long int		time;
	struct timeval	current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_delay(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

long int	spent_time(long int time)
{
	int	current_time;

	current_time = get_time() - time;
	return (current_time);
}

int	cleanup_err(t_info *inf, t_philo *ph, pid_t *pids)
{
	if (pids)
		free(pids);
	if (ph)
		philo_free(ph, inf->nbr_philo);
	if (inf)
		info_destroy(inf);
	write(2, "Error\n", 6);
	return (1);
}

int	cleanup(t_info *inf, t_philo *ph, pid_t *pids)
{
	if (pids)
		free(pids);
	if (ph)
		philo_free(ph, inf->nbr_philo);
	if (inf)
		info_destroy(inf);
	return (1);
}
