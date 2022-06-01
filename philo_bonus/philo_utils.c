/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:42:25 by aait-oma          #+#    #+#             */
/*   Updated: 2022/06/01 14:43:20 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_destroy(t_philo *ph)
{
	sem_close (ph->s_last_meal);
	sem_unlink("s_last_meal");
}

void	philo_free(t_philo *ph, int n)
{
	while (n--)
		philo_destroy(ph + n);
	free(ph);
}
