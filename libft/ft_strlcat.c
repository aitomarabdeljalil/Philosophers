/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:45:27 by syakoubi          #+#    #+#             */
/*   Updated: 2021/11/20 14:21:38 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (src[size])
		size++;
	if (dstsize <= i)
		size += dstsize;
	else
		size += i;
	j = 0;
	if (dstsize != 0)
	{
		while (src[j] != '\0' && i < dstsize - 1)
			dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (size);
}
