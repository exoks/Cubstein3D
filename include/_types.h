/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:35:57 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/28 10:24:37 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TYPES_H
# define _TYPES_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include "MLX42.h"
# include "libft.h"
# include "_define.h"

/* ************************************************************************** */
/*                                   token                                    */
/* ************************************************************************** */
typedef struct s_token
{
	char	*key;
	char	*value;
}	t_token;

/* ************************************************************************** */
/*                                   POINT                                    */
/* ************************************************************************** */
typedef struct s_point
{
	int32_t			x;
	int32_t			y;
}	t_point;

/* ************************************************************************** */
/*                                    RAY                                     */
/* ************************************************************************** */
typedef struct s_ray
{
	t_point			pos_map;
	t_vect2d		direction;
	t_point			step;
	t_vect2d		delta;
	t_vect2d		s_dist;
}	t_ray;

typedef struct s_final_ray
{
	t_vect2d		origin;
	t_vect2d		direction;
	int32_t			side;
	bool			is_door;
	double			distance;
}	t_final_ray;


//====<[ Struct: wall ]>========================================================
typedef struct s_wall
{
	int				height;
	int				y_min;
	int				y_moy;
	int				y_max;
	float			intensity;
	mlx_texture_t	*txtr;
	double			c;
}					t_wall;

/* ************************************************************************** */
/*                                  CAMERA                                    */
/* ************************************************************************** */
typedef struct s_camera
{
	t_vect2d		position;
	t_vect2d		direction;
	t_vect2d		plane;
}	t_camera;

/* ************************************************************************** */
/*                                   ACTION                                   */
/* ************************************************************************** */
typedef struct s_action
{
	mlx_texture_t	*sprite;
	uint32_t		frame;
	uint32_t		frame_size;
	char			*sound;
}	t_action;

/* ************************************************************************** */
/*                                   PLAYER                                   */
/* ************************************************************************** */
typedef struct s_player
{
	mlx_image_t		*img;
	int16_t			mode;
	t_action		action[MAX_ACTION];
	int16_t			active_action;
}	t_player;

//===<[ Struct : Date ]>========================================================
typedef struct s_data
{
	char			**map;
	int32_t			height;
	uint32_t		ceiling;
	uint32_t		floor;
	mlx_texture_t	*door;
	mlx_texture_t	*wall[4];
	int32_t			prespective;
}	t_data;

/* ************************************************************************** */
/*                                   ENGINE                                   */
/* ************************************************************************** */
typedef struct s_engine
{
	mlx_t			*mlx;
	t_data			*data;
	t_camera		*cam;
	mlx_image_t		*view;
	mlx_image_t		*mini;
	t_player		player;
}	t_engine;

#endif /*___TYPES_H__*/
//==============================================================================
