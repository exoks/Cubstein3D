/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:48:10 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/28 10:16:24 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=== action handler : ========================================================
void	action_handler(t_engine *inst)
{
	if (mlx_is_key_down(inst->mlx, MLX_KEY_E))
		aim(inst);
	else if (mlx_is_key_down(inst->mlx, MLX_KEY_SPACE))
		shoot(inst);
	else if (mlx_is_key_down(inst->mlx, MLX_KEY_R))
	{
		inst->player.active_action = CHARGE;
		inst->player.mode = ZOOM_OUT;
	}
}

//=== door_handler : ==========================================================
void	door_handler(t_engine *inst)
{
	static t_vect2d	open;
	t_vect2d		curs;

	curs = ft_add_vect2d(inst->cam->direction, inst->cam->position);
	if (inst->data->map[(int)curs.y][(int)curs.x] == '2')
	{
		inst->data->map[(int)curs.y][(int)curs.x] = '0';
		if (open.x != 0.0 || open.y != 0.0)
			inst->data->map[(int)open.y][(int)open.x] = '2';
		open.x = curs.x;
		open.y = curs.y;
	}
}

//=== key_handler : ============================================================
void	key_handler(t_engine *inst)
{
	static uint16_t	index;

	if (index++ % 2 == 0)
		return ;
	if (mlx_is_key_down(inst->mlx, MLX_KEY_ESCAPE))
		engine_clean(inst, EXIT_SUCCESS);
	if (mlx_is_key_down(inst->mlx, MLX_KEY_LEFT))
		rotate_camera(inst->cam, -STEP_ROT);
	if (mlx_is_key_down(inst->mlx, MLX_KEY_RIGHT))
		rotate_camera(inst->cam, +STEP_ROT);
	if (mlx_is_key_down(inst->mlx, MLX_KEY_W))
		move_camera(inst->cam, +STEP_MOVE, inst->data, FORWARD);
	if (mlx_is_key_down(inst->mlx, MLX_KEY_S))
		move_camera(inst->cam, -STEP_MOVE, inst->data, FORWARD);
	if (mlx_is_key_down(inst->mlx, MLX_KEY_A))
		move_camera(inst->cam, -STEP_MOVE, inst->data, SIDEWAY);
	if (mlx_is_key_down(inst->mlx, MLX_KEY_D))
		move_camera(inst->cam, +STEP_MOVE, inst->data, SIDEWAY);
	if (mlx_is_key_down(inst->mlx, MLX_KEY_F))
		door_handler(inst);
	if (inst->player.active_action == -1)
		action_handler(inst);
}

//===<[ mouse_handler :]>=======================================================
void	mouse_handler(t_engine *inst)
{
	static uint16_t	idex;
	static double	pre;
	int32_t			x;
	int32_t			y;

	mlx_get_mouse_pos(inst->mlx, &x, &y);
	mlx_set_cursor_mode(inst->mlx, MLX_MOUSE_HIDDEN);
	if (idex++ % 2 == 0 && x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		inst->data->prespective = WIN_HEIGHT - y;
		rotate_camera(inst->cam, (x - pre) * 0.4);
		pre = x;
	}
}

//==== mouse_key_handler =======================================================
void	mouse_key_han(mouse_key_t bt, action_t a, modifier_key_t m, void *p)
{
	(void) a;
	(void) m;
	if (bt == MLX_MOUSE_BUTTON_RIGHT)
		aim(p);
	if (bt == MLX_MOUSE_BUTTON_LEFT)
		shoot(p);
}
