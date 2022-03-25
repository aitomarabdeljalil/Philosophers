/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:08:29 by syakoubi          #+#    #+#             */
/*   Updated: 2021/11/07 16:29:37 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*_dst;
	const unsigned char	*_src;

	_dst = dst;
	_src = src;
	if (src < dst)
	{
		while (len--)
			_dst[len] = _src[len];
	}
	else if (src > dst)
	{
		while (len--)
			*(_dst++) = *(_src++);
	}
	return (dst);
}
