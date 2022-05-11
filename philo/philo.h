/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:47:59 by aait-oma          #+#    #+#             */
/*   Updated: 2022/05/11 11:20:35 by aait-oma         ###   ########.fr       */
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
	int		nbr_philo;
	int		time_die;
	int		time_to_eat;
	int		time_sleep;
	int		nbr_pilo_eat;
	bool	philo_die;
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
	pthread_mutex_t	dead;
	pthread_mutex_t	*write_mutex;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
	t_info			*info;
}	t_philo;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*plife(void *arg);
void	info_init(t_info *inf, int ac, char **av);
void	philo_init(t_philo	**ph, t_info inf);

#endif