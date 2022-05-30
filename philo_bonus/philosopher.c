/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:34:44 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/27 20:15:52 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	plife(t_philo *ph)
{
	t_info	*inf;

	inf = ph->info;
	while (ph->nbr_meals == -2 || ph->nbr_meals--)
	{
		sem_wait(inf->forks);
		info_stop_probe(inf);
		printf("%ld	[%d]	has taken a fork\n", spent_time(ph->start), ph->id);
		sem_wait(inf->forks);
		info_stop_probe(inf);
		printf("%ld	[%d]	has taken a fork\n", spent_time(ph->start), ph->id);
		info_stop_probe(inf);
		printf("%ld	[%d]	is eating\n", spent_time(ph->start), ph->id);
		sem_wait(ph->s_last_meal);
		ph->last_meal = get_time();
		sem_post(ph->s_last_meal);
		ft_delay(inf->t_toeat);
		sem_post(inf->forks);
		sem_post(inf->forks);
		info_stop_probe(inf);
		printf("%ld	[%d]	is sleeping\n", spent_time(ph->start), ph->id);
		ft_delay(inf->t_sleep);
		info_stop_probe(inf);
		printf("%ld	[%d]	is thinking\n", spent_time(ph->start), ph->id);
	}
	exit(0);
}

void	*monitor(void *arg)
{
	t_philo	*ph;
	t_info	*inf;
	long	t_last_meal;

	ph = (t_philo *)arg;
	inf = ph->info;
	while (1)
	{
		sem_wait(ph->s_last_meal);
		t_last_meal = ph->last_meal;
		sem_post(ph->s_last_meal);
		if (get_time() - t_last_meal > inf->t_die)
		{
			info_die(inf);
			printf("%ld	[%d]	has died\n", spent_time(ph->start), ph->id);
			exit(1);
		}
		usleep(100);
	}
}

pid_t	philo_launch(t_philo *ph)
{
	pthread_t	thr;
	pid_t		pid;

	pid = fork();
	if (pid)
		return (pid);
	if (pthread_create(&thr, NULL, monitor, ph))
		exit(2);
	if (ph->id % 2)
		usleep(1000);
	plife(ph);
	return (pid);
}

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

bool	philo_init(t_philo *ph, t_info *inf, int i)
{
	ph->info = inf;
	ph->id = i + 1;
	ph->nbr_meals = inf->pilo_t_eat;
	ph->last_meal = get_time();
	ph->start = get_time();
	sem_unlink("s_last_meal");
	ph->s_last_meal = sem_open("s_last_meal", O_CREAT | O_EXCL, 0644, 1);
	if (ph->s_last_meal == SEM_FAILED)
	{
		sem_unlink("s_last_meal");
		return (false);
	}
	return (true);
}

t_philo	*create_philos(t_info *inf)
{
	t_philo	*ph;
	int		i;

	ph = malloc(inf->nbr_philo * sizeof(t_philo));
	if (!ph)
		return (NULL);
	i = 0;
	while (i < inf->nbr_philo)
	{
		if (!philo_init(ph + i, inf, i))
		{
			philo_free(ph, i);
			return (NULL);
		}
		i++;
	}
	return (ph);
}
