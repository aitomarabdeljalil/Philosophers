/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:42:33 by aait-oma          #+#    #+#             */
/*   Updated: 2022/03/27 16:17:00 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

//av[1] = number_of_philosophers
//av[2] = time_to_die
//av[3] = time_to_eat
//av[4] = time_to_sleep
//av[5] = number_of_times_each_philosopher_must_eat
int main(int ac, char **av)
{
	if ((ac < 5 || ac > 6) && printf("error\n"))
		return (0);
	
	return (0);
}
