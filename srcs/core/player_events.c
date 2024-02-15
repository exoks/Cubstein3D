/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:11:10 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/18 17:46:15 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//==== move_camera =============================================================
void	move_camera(t_camera *cam, double mv_step, t_data *data, int32_t move)
{
	t_vect2d	new;
	t_vect2d	step;

	if (move == FORWARD)
		step = ft_scale_vect2d(cam->direction, mv_step);
	if (move == SIDEWAY)
		step = ft_scale_vect2d(cam->plane, mv_step);
	new = ft_add_vect2d(cam->position, step);
	if (data->map[(int)(new.y + 0.06)][(int)(new.x)] != '0')
		return ;
	if (data->map[(int)(new.y - 0.06)][(int)(new.x)] != '0')
		return ;
	if (data->map[(int)(new.y)][(int)(new.x + 0.06)] != '0')
		return ;
	if (data->map[(int)(new.y)][(int)(new.x - 0.06)] != '0')
		return ;
	cam->position = new;
}

//==== rotate_camera ===========================================================
void	rotate_camera(t_camera *cam, double angle)
{
	angle *= M_PI / 180;
	cam->direction = ft_rotate_vect2d(cam->direction, angle);
	cam->plane = ft_rotate_vect2d(cam->plane, angle);
}

//==== aim_event ===============================================================
void	aim(t_engine *inst)
{
	int32_t	mode;

	mode = inst->player.mode;
	inst->player.mode = ZOOM_IN * (mode == ZOOM_OUT);
	inst->player.mode += ZOOM_OUT * (mode == ZOOM_IN);
	inst->player.active_action = inst->player.mode;
}

//=== shoot_event ==============================================================
void	shoot(t_engine *inst)
{
	int32_t	mode;

	mode = inst->player.mode;
	inst->player.active_action = SHOOT_1 * (mode == ZOOM_OUT);
	inst->player.active_action += SHOOT_2 * (mode == ZOOM_IN);
}
