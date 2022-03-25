/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:52:22 by sayar             #+#    #+#             */
/*   Updated: 2021/11/13 16:04:57 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cal_one(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_numwordes(const char *s, char c)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			cmp++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cmp);
}

static char	**ft_memclean(char **array, int size)
{
	int	i;

	if (array)
	{
		i = 0;
		while (i < size)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
		free(array);
	}
	return (NULL);
}

static char	**ft_fillup(const char *s, char c, char **array)
{
	int	i;
	int	j;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			continue ;
		array[i] = malloc(sizeof(char) * (ft_cal_one(s, c) + 1));
		if (array[i] == NULL)
			return (ft_memclean(array, i));
		j = 0;
		while (*s != c && *s)
		{
			array[i][j] = *s;
			j++;
			s++;
		}
		array[i][j] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_numwordes(s, c) + 1));
	if (array == NULL)
		return (NULL);
	ft_fillup(s, c, array);
	return (array);
}
