/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:54:27 by oezzaou           #+#    #+#             */
/*   Updated: 2023/10/24 19:45:02 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=== init_camera : ============================================================
t_camera	*init_camera(char **map)
{
	t_camera	*cam;
	int			x;
	int			y;

	y = -1;
	cam = ft_calloc(1, sizeof(t_camera));
	if (cam == NULL || map == NULL)
		return (free(cam), NULL);
	cam->position = (t_vect2d){-1, -1};
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				if (cam->position.x != -1)
					return (ft_perror("Duplicated Player"), free(cam), NULL);
				set_camera(cam, x, y, &map[y][x]);
			}
		}
	}
	if (cam->position.x == -1)
		return (ft_perror("Player Not found"), free(cam), NULL);
	return (cam);
}

//====< set_camera >============================================================
void	set_camera(t_camera *cam, int x, int y, char *dir)
{
	cam->position = (t_vect2d){x + 0.5, y + 0.5};
	if (*dir == 'N')
	{
		cam->direction = (t_vect2d){0, -1};
		cam->plane = (t_vect2d){0.66, 0};
	}
	else if (*dir == 'S')
	{
		cam->direction = (t_vect2d){0, 1};
		cam->plane = (t_vect2d){-0.66, 0};
	}
	else if (*dir == 'W')
	{
		cam->direction = (t_vect2d){-1, 0};
		cam->plane = (t_vect2d){0, -0.66};
	}
	else if (*dir == 'E')
	{
		cam->direction = (t_vect2d){1, 0};
		cam->plane = (t_vect2d){0, 0.66};
	}
	*dir = '0';
}
