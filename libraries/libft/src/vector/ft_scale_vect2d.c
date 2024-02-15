/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_vect2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:04:33 by hael-mou          #+#    #+#             */
/*   Updated: 2023/09/18 00:52:30 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect2d	ft_scale_vect2d(t_vect2d vector, double scale)
{
	vector.x *= scale;
	vector.y *= scale;
	return (vector);
}
