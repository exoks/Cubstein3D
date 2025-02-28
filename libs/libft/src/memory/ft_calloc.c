/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:36:48 by oezzaou           #+#    #+#             */
/*   Updated: 2025/02/28 17:22:52 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_calloc: ]>==========================================================
void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;
	size_t	i;

	if (!count || !size)
		return (NULL);
	pt = (void *) malloc(count * size);
	if (!pt)
		return (0);
	i = 0;
	while (i < size * count)
		*((char *)pt + i++) = 0;
	return (pt);
}
