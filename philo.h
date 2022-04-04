/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:11:52 by aait-oma          #+#    #+#             */
/*   Updated: 2022/04/04 16:54:18 by aait-oma         ###   ########.fr       */
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

# define THINKING 1
# define SLEEPING 2
# define EATING 3

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
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
	t_info			*info;
}	t_philo;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);

#endif