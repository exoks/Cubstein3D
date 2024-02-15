/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:28:09 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/24 15:49:42 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=== load_player ==============================================================
bool	load_player(t_player *player)
{
	player->mode = ZOOM_OUT;
	player->active_action = CHARGE;
	player->action[SHOOT_1].sprite = mlx_load_png("assets/guns/shoot.png");
	player->action[SHOOT_1].frame_size = 1509;
	player->action[SHOOT_1].frame = 0;
	player->action[SHOOT_2].sprite = mlx_load_png("assets/guns/shoot2.png");
	player->action[SHOOT_2].frame_size = 1509;
	player->action[SHOOT_2].frame = 0;
	player->action[ZOOM_IN].sprite = mlx_load_png("assets/guns/zoom_in.png");
	player->action[ZOOM_IN].frame_size = 1509;
	player->action[ZOOM_IN].frame = 0;
	player->action[ZOOM_OUT].sprite = mlx_load_png("assets/guns/zoom_out.png");
	player->action[ZOOM_OUT].frame_size = 1509;
	player->action[ZOOM_OUT].frame = 0;
	player->action[CHARGE].sprite = mlx_load_png("assets/guns/charge.png");
	player->action[CHARGE].frame_size = 1509;
	player->action[CHARGE].frame = 0;
	if (!player->action[0].sprite || !player->action[2].sprite
		|| !player->action[3].sprite || !player->action[4].sprite)
		return (false);
	return (true);
}
