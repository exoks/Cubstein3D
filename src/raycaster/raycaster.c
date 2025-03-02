/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:45:33 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/20 11:13:14 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=== get grid dist : =========================================================
static double	get_grid_dist(double pos, int32_t map, double dir)
{
	if (dir <= 0)
		return (pos - map);
	return (map + 1.0 - pos);
}

//=== get new ray : ===========================================================
static t_ray	get_new_ray(t_vect2d pos, t_vect2d dir)
{
	t_ray		ray;

	ray.direction = dir;
	ray.pos_map = (t_point){.x = pos.x, .y = pos.y};
	ray.delta.x = fabs(1 / (dir.x + 0.01 * (dir.x == 0.0)));
	ray.delta.y = fabs(1 / (dir.y + 0.01 * (dir.y == 0.0)));
	ray.s_dist.x = get_grid_dist(pos.x, ray.pos_map.x, dir.x) * ray.delta.x;
	ray.s_dist.y = get_grid_dist(pos.y, ray.pos_map.y, dir.y) * ray.delta.y;
	ray.step.x = 1 - 2 * (dir.x < 0);
	ray.step.y = 1 - 2 * (dir.y < 0);
	return (ray);
}

//=== reycaster : =============================================================
t_final_ray	raycaster(t_vect2d start, t_vect2d ray_dir, t_data *data)
{
	t_ray       ray;
	t_final_ray	fray;

	ray = get_new_ray(start, ray_dir);
	while (data->map[ray.pos_map.y][ray.pos_map.x] == '0')
	{
		if (ray.s_dist.x < ray.s_dist.y)
		{
			fray.side = VERTICAL;
			ray.pos_map.x += ray.step.x;
			ray.s_dist.x += ray.delta.x;
		}
		else
		{
			fray.side = HORIZONTAL;
			ray.pos_map.y += ray.step.y;
			ray.s_dist.y += ray.delta.y;
		}
	}
	fray.origin = start;
	fray.direction = ray_dir;
	fray.distance = (ray.s_dist.x - ray.delta.x) * (fray.side == VERTICAL);
	fray.distance += (ray.s_dist.y - ray.delta.y) * (fray.side == HORIZONTAL);
	fray.is_door = data->map[ray.pos_map.y][ray.pos_map.x] == '2';
	return (fray);
}
