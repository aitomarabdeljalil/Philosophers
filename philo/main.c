/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:23:12 by aait-oma          #+#    #+#             */
/*   Updated: 2022/06/02 17:12:19 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	inf;
	t_philo	*ph;
	int		i;

	if ((ac < 5 || ac > 6) && printf("error\n"))
		return (0);
	if (!info_init(&inf, ac, av))
		return (0);
	ph = malloc(inf.nbr_philo * sizeof(t_philo));
	if (!ph)
		return (0);
	philo_init(&ph, inf);
	i = 0;
	while (i < inf.nbr_philo)
	{
		pthread_create(&(ph[i].pt), NULL, &plife, &ph[i]);
		i++;
	}
	main_check(ph);
	return (0);
}
