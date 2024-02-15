/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_vect2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:48:17 by hael-mou          #+#    #+#             */
/*   Updated: 2023/09/18 00:52:27 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect2d	ft_rotate_vect2d(t_vect2d vector, double angle)
{
	double	tmp_x;

	tmp_x = vector.x;
	vector.x = cos(angle) * tmp_x - sin(angle) * vector.y;
	vector.y = sin(angle) * tmp_x + cos(angle) * vector.y;
	return (vector);
}
