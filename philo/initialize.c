/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:26:26 by aait-oma          #+#    #+#             */
/*   Updated: 2022/06/03 10:43:47 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <errno.h>

int	conv_arg(char *str)
{
	int	i;
	int	nbr;

	if (!str)
		return (-2);
	i = 0;
	if (*str == '\0')
		return (-1);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (-1);
	errno = 0;
	nbr = ft_atoi(str);
	if (errno == 1 || nbr < 1)
		return (-1);
	return (nbr);
}

bool	info_init(t_info *inf, int ac, char **av)
{
	inf->nbr_philo = conv_arg(av[1]);
	inf->time_die = conv_arg(av[2]);
	inf->time_to_eat = conv_arg(av[3]);
	inf->time_sleep = conv_arg(av[4]);
	if (ac == 5)
		inf->nbr_pilo_eat = -2;
	else
		inf->nbr_pilo_eat = conv_arg(av[5]);
	inf->death_index = -1;
	if (inf->nbr_philo == -1 || inf->time_die == -1
		|| inf->time_to_eat == -1 || inf->time_sleep == -1
		|| inf->nbr_pilo_eat == -1)
	{
		printf("args error!!\n");
		return (false);
	}
	return (true);
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
		(*ph)[i].nbr_meals = inf.nbr_pilo_eat;
		(*ph)[i].last_meal = get_time();
		(*ph)[i].start = get_time();
		pthread_mutex_init(&(*ph)[i].left, NULL);
		i++;
	}
}
