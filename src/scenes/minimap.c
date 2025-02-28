/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:24:35 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/24 19:58:32 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=== get_color : ==============================================================
static uint32_t	get_color(t_data *data, double i, double j)
{
	if (i < 0 || j < 0 || j >= data->height)
		return (0x0098DBff);
	if (i >= ft_strlen(data->map[(int)j]))
		return (0x0098DBff);
	if (data->map[(int)j][(int)i] == '1')
		return (0xff0000ff);
	if (data->map[(int)j][(int)i] == '2')
		return (0x3333ffff);
	if (data->map[(int)j][(int)i] == ' ')
		return (0x0098DBff);
	return (0xffffffff);
}

//=== minimap : ================================================================
void	minimap(mlx_image_t *img, t_data *data, t_vect2d cam)
{
	double		angle;
	double		radius;
	uint32_t	color;
	t_vect2d	pnt;

	radius = 150;
	cam.x *= 25;
	cam.y *= 25;
	while (--radius)
	{
		angle = 360;
		while (angle >= 0)
		{
			pnt.x = (radius * cosf(angle * M_PI / 180));
			pnt.y = (radius * sinf(angle * M_PI / 180));
			color = get_color(data, (pnt.x + cam.x) / 25, (pnt.y + cam.y) / 25);
			mlx_pixel_put(img, pnt.x + 170, pnt.y + 170, color * (radius >= 5));
			angle -= 1.5;
		}
	}
}
