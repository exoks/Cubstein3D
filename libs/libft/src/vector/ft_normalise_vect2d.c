/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalise_vect2d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:42:35 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/06 15:57:32 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect2d	ft_normalise_vect2d(t_vect2d vector)
{
	double	magnitude;

	magnitude = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (magnitude != 0.0)
		vector = ft_scale_vect2d(vector, 1.0 / magnitude);
	return (vector);
}
