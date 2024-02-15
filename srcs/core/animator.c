/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:54:27 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/18 17:55:05 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=== play_animation : ========================================================
void	play_action(mlx_image_t *img, t_action *action, int16_t *active)
{
	uint32_t	img_y;
	uint32_t	width;
	uint8_t		*pexels;

	img_y = -1;
	width = action->sprite->width - action->frame;
	width = width * (width <= img->width) + img->width * (img->width < width);
	if (action->frame >= action->sprite->width)
	{
		action->frame = 0;
		*active = -1;
		return ;
	}
	while (++img_y < img->height && img_y < action->sprite->height)
	{
		pexels = action->sprite->pixels;
		pexels += (img_y * action->sprite->width + action->frame) * 4;
		ft_memmove(&img->pixels[img_y * img->width * 4], pexels, width * 4);
	}
	action->frame += action->frame_size;
}

//== animator : ===============================================================
void	animator(t_engine *engine)
{
	static uint16_t	index;
	static double	t_acm;
	t_action		*anime;

	if (index++ % 2 == 0 && engine->player.active_action != -1)
	{
		t_acm += engine->mlx->delta_time;
		while (t_acm >= TIME_OF_SMALL_MOVE)
		{
			usleep(250);
			t_acm -= TIME_OF_SMALL_MOVE;
		}
		anime = &engine->player.action[engine->player.active_action];
		play_action(engine->player.img, anime, &engine->player.active_action);
	}
}
