/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:47:59 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/30 18:34:34 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_info
{
	int				nbr_philo;
	int				time_die;
	int				time_to_eat;
	int				time_sleep;
	int				nbr_pilo_eat;
	long			death_time;
	int				death_index;
	pthread_mutex_t	death_mutex;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		pt;
	int				lp;
	int				rp;
	long int		last_meal;
	int				nbr_meals;
	long int		start;
	pthread_mutex_t	mutex;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
	t_info			*info;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		*plife(void *arg);
void		info_init(t_info *inf, int ac, char **av);
void		philo_init(t_philo	**ph, t_info inf);
void		ft_takefork(t_philo *ph);
void		ft_eating(t_philo *ph);
void		ft_sleeping(t_philo *ph);
void		ft_thinking(t_philo *ph);
int			isdead(t_philo *ph);
void		main_check(t_philo *ph);
long int	get_time(void);
void		ft_delay(long time);
long int	spent_time(long int time);
#endif