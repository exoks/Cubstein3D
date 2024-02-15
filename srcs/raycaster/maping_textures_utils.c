/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_textures_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:16:33 by oezzaou           #+#    #+#             */
/*   Updated: 2023/10/20 11:17:08 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//==== change_pixel_intensity ==================================================
uint32_t	change_pixel_intensity(uint32_t pixel, float intensity)
{
	uint32_t	new_pixel;
	uint8_t		*byte;

	if (intensity > 1.0)
		intensity = 1.0;
	byte = (uint8_t *) &pixel;
	new_pixel = (int)(byte[3] * intensity) << 24;
	new_pixel |= (int)(byte[2] * intensity) << 16;
	new_pixel |= (int)(byte[1] * intensity) << 8;
	new_pixel |= (int)(byte[0] * intensity);
	return (new_pixel);
}
