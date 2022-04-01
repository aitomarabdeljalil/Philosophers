/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:42:33 by aait-oma          #+#    #+#             */
/*   Updated: 2022/03/30 17:22:52 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	av[1] = number_of_philosophers
	av[2] = time_to_die
	av[3] = time_to_eat
	av[4] = time_to_sleep
	av[5] = number_of_times_each_philosopher_must_eat
*/
void	info_init(t_info *inf, int ac, char **av)
{
	inf->nbr_philo = ft_atoi(av[1]);
	inf->time_die = ft_atoi(av[2]);
	inf->time_eat = ft_atoi(av[3]);
	inf->time_sleep = ft_atoi(av[4]);
	if (ac == 5)
		inf->nbr_pilo_eat = -1;
	else
		inf->nbr_pilo_eat = ft_atoi(av[5]);
}

int main(int ac, char **av)
{
	t_info	inf;
	t_philo	*ph;

	if ((ac < 5 || ac > 6) && printf("error\n"))
		return (0);
	info_init(&inf, ac, av);
	ph = malloc(inf.nbr_philo * sizeof(t_philo));
	if (!ph)
		return (0);
	return (0);
}
