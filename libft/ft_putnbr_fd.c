/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:53:00 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/07 12:00:04 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdig(int d, int fd)
{
	char	dig;

	dig = d + '0';
	write(fd, &dig, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n <= -10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putdig(-(n % -10), fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putdig(-n, fd);
	}	
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putdig(n % 10, fd);
	}
	else if (n >= 0)
	{
		ft_putdig(n, fd);
	}
}
