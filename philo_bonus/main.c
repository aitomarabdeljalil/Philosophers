/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:49:27 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/30 13:25:37 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	killpids(pid_t *pids, int sig, int n)
{
	while (n--)
		kill(pids[n], sig);
}

pid_t	*philo_pids(t_philo *ph, int n)
{
	pid_t	*pids;
	int		i;

	pids = malloc(n * sizeof(pid_t));
	if (!pids)
		return (NULL);
	i = 0;
	while (i < n)
	{
		pids[i] = philo_launch(ph + i);
		if (pids[i] == -1)
		{
			killpids(pids, SIGTERM, i);
			free(pids);
			return (NULL);
		}
		i++;
	}
	return (pids);
}

bool	wait_for_philos(pid_t *pids, t_info *inf)
{
	int		stats;
	bool	is_err;

	is_err = false;
	while (waitpid(-1, &stats, 0) > 0)
	{
		if (is_err || !WIFEXITED(stats))
			continue ;
		if (WEXITSTATUS(stats) == 2)
			is_err = true;
		else if (WEXITSTATUS(stats) == 1)
			killpids(pids, SIGTERM, inf->nbr_philo);
	}
	return (!is_err);
}

int	main(int ac, char **av)
{
	t_info	inf;
	t_philo	*ph;
	pid_t	*pids;

	if (ac < 5 || ac > 6)
	{
		write (2, "Error in argument\n", 18);
		return (1);
	}
	if (!info_init(&inf, ac, av))
		return (cleanup_err(&inf, NULL, NULL));
	ph = create_philos(&inf);
	if (!ph)
		return (cleanup_err(&inf, ph, NULL));
	pids = philo_pids(ph, inf.nbr_philo);
	if (!pids)
		return (cleanup_err(&inf, ph, pids));
	if (wait_for_philos(pids, &inf))
		return (cleanup(&inf, ph, pids));
	return (cleanup_err(&inf, ph, pids));
}
