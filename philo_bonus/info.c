/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:39:21 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/30 13:25:43 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <errno.h>

int	conv_arg(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	if (*str == '\0')
		return (-1);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (-1);
	errno = 0;
	nbr = ft_atoi(str);
	if (errno == 1)
		return (-1);
	return (nbr);
}

bool	info_init(t_info *inf, int ac, char **av)
{
	inf->nbr_philo = conv_arg(av[1]);
	inf->t_die = conv_arg(av[2]);
	inf->t_toeat = conv_arg(av[3]);
	inf->t_sleep = conv_arg(av[4]);
	if (ac == 5)
		inf->pilo_t_eat = -2;
	else
		inf->pilo_t_eat = conv_arg(av[5]);
	inf->death_index = -1;
	if (inf->nbr_philo == -1 || inf->t_die == -1
		|| inf->t_toeat == -1 || inf->t_sleep == -1
		|| inf->pilo_t_eat == -1)
		return (false);
	sem_unlink("forks");
	sem_unlink("death");
	inf->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, inf->nbr_philo);
	inf->death = sem_open("death", O_CREAT | O_EXCL, 0644, 1);
	if (inf->forks == SEM_FAILED || inf->death == SEM_FAILED)
	{
		sem_unlink("forks");
		sem_unlink("death");
		return (false);
	}
	return (true);
}

void	info_stop_probe(t_info *inf)
{
	sem_wait(inf->death);
	sem_post(inf->death);
}

void	info_die(t_info *inf)
{
	sem_wait(inf->death);
}

void	info_destroy(t_info *info)
{
	sem_close(info->death);
	sem_unlink("death");
	sem_close(info->forks);
	sem_unlink("forks");
}
