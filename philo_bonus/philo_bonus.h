/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:58:02 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/27 20:04:09 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_info
{
	int				nbr_philo;
	int				t_die;
	int				t_toeat;
	int				t_sleep;
	int				pilo_t_eat;
	long			death_time;
	int				death_index;
	sem_t			*death;
	sem_t			*forks;
}	t_info;

typedef struct s_philo
{
	t_info	*info;
	int		id;
	int		pid;
	long	last_meal;
	sem_t	*s_last_meal;
	int		nbr_meals;
	long	start;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
bool		info_init(t_info *inf, int ac, char **av);
void		info_stop_probe(t_info *inf);
void		info_die(t_info *inf);
void		info_destroy(t_info *inf);
void		killpids(pid_t *pids, int sig, int n);
pid_t		*philo_pids(t_philo *ph, int n);
bool		wait_for_philos(pid_t *pids, t_info *inf);
// void		info_destroy(t_info *info);
int			cleanup_err(t_info *inf, t_philo *ph, pid_t *pids);
int			cleanup(t_info *inf, t_philo *ph, pid_t *pids);
void		plife(t_philo	*ph);
void		*monitor(void *arg);
pid_t		philo_launch(t_philo *ph);
void		philo_destroy(t_philo *ph);
void		philo_free(t_philo *ph, int n);
bool		philo_init(t_philo *ph, t_info *inf, int i);
t_philo		*create_philos(t_info *inf);
long int	get_time(void);
void		ft_delay(long time);
long int	spent_time(long int time);

#endif