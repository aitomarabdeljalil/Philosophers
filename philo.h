/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:11:52 by aait-oma          #+#    #+#             */
/*   Updated: 2022/04/01 12:08:19 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
# define PHILO
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

# define THINKING 1
# define SLEEPING 2
# define EATING 3

typedef struct s_info
{
	int	nbr_philo;
	int	time_die;
	int	time_eat;
	int time_sleep;
	int	nbr_pilo_eat;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		pt;
	int 			lp;
	int 			rp;
	int				state;
	pthread_mutex_t left;
	pthread_mutex_t *right;
	t_info			info;
}	t_philo;



int	ft_atoi(const char *str);
int	ft_isdigit(int c);
#endif