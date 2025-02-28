/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:26:45 by hael-mou          #+#    #+#             */
/*   Updated: 2023/10/24 17:48:57 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//=== cub3d main : =============================================================
int	main(int number_argument, char const *argv[])
{
	t_engine	inst;

	if (number_argument == NUMBER_ARG_ALLOW)
	{
		engine_init(&inst);
		inst.data = loader(argv[1]);
		if (inst.data == NULL)
			engine_clean(&inst, EXIT_FAILURE);
		inst.cam = init_camera(inst.data->map);
		if (inst.cam == NULL || load_player(&inst.player) == false)
			engine_clean(&inst, EXIT_FAILURE);
		engine_start(&inst);
	}
	return (EXIT_FAILURE);
}
