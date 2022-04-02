/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:42:33 by aait-oma          #+#    #+#             */
/*   Updated: 2022/04/02 19:43:18 by aait-oma         ###   ########.fr       */
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
		(*ph)[i].info = inf;
		pthread_mutex_init(&(*ph)[i].left, NULL);
		i++;
	}
}

void	ft_takefork(t_philo *ph)
{
	pthread_mutex_lock(ph->right);
	printf("has taken a fork");
	pthread_mutex_lock(&ph->left);
	printf("has taken a fork");
}

void	ft_eating(t_philo *ph)
{
	printf("is eating");
	usleep(ph->info.time_eat);
}

void	ft_sleeping()
{
	
}

void	*plife(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(ph->info.time_die / 2);
	while (1)
	{
		ft_takefork(ph);
		ft_eating(ph);
		ft_sleeping();
	}

}

int main(int ac, char **av)
{
	t_info	inf;
	t_philo	*ph;
	int		i;

	if ((ac < 5 || ac > 6) && printf("error\n"))
		return (0);
	info_init(&inf, ac, av);
	ph = malloc(inf.nbr_philo * sizeof(t_philo));
	if (!ph)
		return (0);
	philo_init(&ph, inf);
	i = 0;
	while (i < inf.nbr_philo)
	{
		pthread_create(&(ph[i].pt), NULL, &plife, NULL);
		pthread_join(ph[i].pt, NULL);
		i++;
	}
	return (0);
}
