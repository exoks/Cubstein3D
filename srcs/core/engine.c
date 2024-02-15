/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:31:05 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/24 17:50:42 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=== engine_init : ============================================================
void	engine_init(t_engine *inst)
{
	inst->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, false);
	ft_bzero(&inst->player, sizeof(t_player));
	if (inst->mlx != NULL)
	{
		inst->mini = mlx_new_image(inst->mlx, 400, 400);
		inst->view = mlx_new_image(inst->mlx, WIN_WIDTH, WIN_HEIGHT);
		inst->player.img = mlx_new_image(inst->mlx, WIN_WIDTH, WIN_HEIGHT);
	}
	if (!inst->mlx || !inst->mini || !inst->view || !inst->player.img)
		engine_clean(inst, EXIT_FAILURE);
}

//=== engine_clean : ===========================================================
void	engine_clean(t_engine *inst, int exit_status)
{
	int	index;

	index = -1;
	if (inst && inst->mlx != NULL)
	{
		mlx_delete_image(inst->mlx, inst->mini);
		mlx_delete_image(inst->mlx, inst->view);
		mlx_delete_image(inst->mlx, inst->player.img);
		mlx_terminate(inst->mlx);
	}
	if (inst && inst->data != NULL)
		clean_data(inst->data);
	while (++index < 4)
	{
		if (inst->player.action[index].sprite != NULL)
			mlx_delete_texture(inst->player.action[index].sprite);
	}
	exit(exit_status);
}

//=== render : =================================================================
static void	render(t_engine *inst)
{
	static uint16_t	index;

	if (index++ % 2 == 0)
	{
		minimap(inst->mini, inst->data, inst->cam->position);
		render_view(inst->view, inst->cam, inst->data);
	}
}

//=== engine_start : ===========================================================
void	engine_start(t_engine *inst)
{
	mlx_image_to_window(inst->mlx, inst->view, 0, 0);
	mlx_image_to_window(inst->mlx, inst->player.img, 200, 0);
	mlx_image_to_window(inst->mlx, inst->mini, 0, 0);
	mlx_loop_hook(inst->mlx, render, inst);
	mlx_loop_hook(inst->mlx, animator, inst);
	mlx_loop_hook(inst->mlx, mouse_handler, inst);
	mlx_loop_hook(inst->mlx, key_handler, inst);
	mlx_mouse_hook(inst->mlx, mouse_key_han, inst);
	mlx_loop(inst->mlx);
}
