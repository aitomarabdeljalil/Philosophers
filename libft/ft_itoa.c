/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:48:59 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/24 18:26:52 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//count digit of a number
static int	ft_count_digit(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_swap(char *a, char *b)
{
	char	swapvar;

	swapvar = *a;
	*a = *b;
	*b = swapvar;
}

static void	ft_reverse(char *str, int length)
{
	int	start;
	int	end;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		ft_swap(str + start, str + end);
		start++;
		end--;
	}
}

static int	ft_mod(int x, int y)
{
	int	res;

	res = x % y;
	if (res < 0)
		res *= -1;
	return (res);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	bool	isneg;

	i = 0;
	isneg = false;
	if (n < 0)
		isneg = true;
	if (isneg)
		str = malloc(sizeof(char) * (ft_count_digit(n) + 2));
	else
		str = malloc(sizeof(char) * (ft_count_digit(n) + 1));
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i++] = ft_mod(n, 10) + 48;
		n = n / 10;
	}
	if (isneg)
		str[i++] = '-';
	ft_reverse(str, i);
	str[i++] = '\0';
	return (str);
}
