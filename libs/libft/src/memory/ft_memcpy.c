/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:04:08 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/02 21:39:06 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_memcpy: ]>==========================================================
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char    *med;
	size_t	index;

	med = (char *) dst;
	if (dst != src)
	{
		index = 0;
		while (index < n)
		{
			med[index] = *((char *)src + index);
			index++;
		}
	}
	return (dst);
}
