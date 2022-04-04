/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:42:33 by aait-oma          #+#    #+#             */
/*   Updated: 2022/04/04 17:47:12 by aait-oma         ###   ########.fr       */
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

long int    get_time(void)
{
    long int            time;
    struct timeval        current_time;

    time = 0;
    gettimeofday(&current_time, NULL);
    time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return (time);
}

long int	spent_time(long int time)
{
	int current_time;

	current_time = get_time() - time;
	return (current_time);
}


int	isdead(t_philo *ph)
{
	if (ph->info->nbr_pilo_eat != 0)
		if (ph->nbr_meals == ph->info->nbr_pilo_eat)
			return (-1);
	if (get_time() - ph->last_meal > ph->info->time_die)
	{
		printf("%ld	[%d]	died\n", spent_time(ph->start), ph->id);
		ph->info->philo_die = true;
		return (-1);
	}
	return (0);
}

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
		pthread_mutex_init(&(*ph)[i].left, NULL);
		i++;
	}
}

void	ft_takefork(t_philo *ph)
{
	pthread_mutex_lock(ph->right);
	printf("%ld	[%d]	has taken a fork\n", spent_time(ph->start), ph->id);
	pthread_mutex_lock(&ph->left);
	printf("%ld	[%d]	has taken a fork\n", spent_time(ph->start), ph->id);
}

void	ft_eating(t_philo *ph)
{
	long int	lmeal;

	lmeal = spent_time(ph->start);
	printf("%ld	[%d]	is eating\n", lmeal, ph->id);
	ph->last_meal = lmeal;
	usleep(ph->info->time_to_eat * 1000);
	ph->nbr_meals++;
	pthread_mutex_unlock(ph->right);
	pthread_mutex_unlock(&ph->left);
}

void	ft_sleeping(t_philo *ph)
{
	printf("%ld	[%d]	is sleeping\n", spent_time(ph->start), ph->id);
	usleep(ph->info->time_sleep * 1000);
}

void	ft_thinking(t_philo *ph)
{
	printf("%ld	[%d]	is thinking\n", spent_time(ph->start), ph->id);
}

void	*plife(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(ph->info->time_die / 2);
	while (!isdead(ph) && ph->info->philo_die == false)
	{
		ft_takefork(ph);
		ft_eating(ph);
		ft_sleeping(ph);
		ft_thinking(ph);
	}
	return (NULL);
}

int	main(int ac, char **av)
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
		pthread_create(&(ph[i].pt), NULL, &plife, &ph[i]);
		i++;
	}
	i = 0;
	while (i < inf.nbr_philo)
	{
		pthread_join(ph[i].pt, NULL);
		i++;
	}
	return (0);
}
