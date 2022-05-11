/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:26:26 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/11 11:19:48 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	info_init(t_info *inf, int ac, char **av)
{
	inf->nbr_philo = ft_atoi(av[1]);
	inf->time_die = ft_atoi(av[2]);
	inf->time_to_eat = ft_atoi(av[3]);
	inf->time_sleep = ft_atoi(av[4]);
	if (ac == 5)
		inf->nbr_pilo_eat = 0;
	else
		inf->nbr_pilo_eat = ft_atoi(av[5]);
	inf->philo_die = false;
}

void	philo_init(t_philo	**ph, t_info inf)
{
	int	i;

	i = 0;
	while (i < inf.nbr_philo)
	{
		(*ph)[i].id = i + 1;
		if ((*ph)[i].id == 1)
			(*ph)[i].lp = inf.nbr_philo;
		else
			(*ph)[i].lp = i;
		if (i == inf.nbr_philo - 1)
			(*ph)[i].rp = 1;
		else
			(*ph)[i].rp = i + 2;
		(*ph)[i].right = &(*ph)[(*ph)[i].rp - 1].left;
		(*ph)[i].info = &inf;
		(*ph)[i].nbr_meals = 0;
		(*ph)[i].last_meal = get_time();
		(*ph)[i].start = get_time();
		(*ph)[i].write_mutex = write_mutex;
		pthread_mutex_init(&(*ph)[i].left, NULL);
		i++;
	}
}
