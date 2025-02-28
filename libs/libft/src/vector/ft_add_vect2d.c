/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_vect2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:33:57 by hael-mou          #+#    #+#             */
/*   Updated: 2023/09/18 00:52:20 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect2d	ft_add_vect2d(t_vect2d vector1, t_vect2d vector2)
{
	vector1.x += vector2.x;
	vector1.y += vector2.y;
	return (vector1);
}
