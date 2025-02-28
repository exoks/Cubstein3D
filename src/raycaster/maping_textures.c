//  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
//  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀       𓐓  maping_textures.c 𓐔           
//  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
//  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀      Dev: oezzaou <oussama.ezzaou@gmail.com> 
//  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
//  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
//  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2023/10/15 09:39:35 by oezzaou
//  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/02/28 10:21:51 by oezzaou
//  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
//  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
//  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
//  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
//  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

#include "cub3d.h"

//====<[ get_wall_info: ]>======================================================
static void	get_wall_info(t_wall *wall, t_final_ray *ray, t_data *data)
{
	wall->height = WIN_WIDTH / (1.4 * ray->distance);
	wall->y_moy = data->prespective;
	wall->y_min = wall->y_moy - (wall->height / 2);
	wall->y_max = wall->y_min + wall->height;
	wall->c = WIN_HEIGHT * SMOKE_EFFECT;
	wall->intensity = wall->height / wall->c;
	if (ray->side == VERTICAL && ray->direction.x > 0)
		wall->txtr = data->wall[EAST];
	if (ray->side == VERTICAL && ray->direction.x < 0)
		wall->txtr = data->wall[WEST];
	if (ray->side == HORIZONTAL && ray->direction.y < 0)
		wall->txtr = data->wall[NORTH];
	if (ray->side == HORIZONTAL && ray->direction.y > 0)
		wall->txtr = data->wall[SOUTH];
	if (ray->is_door == true)
		wall->txtr = data->door;
}

//====<[ get_xp: ]>=============================================================
static float	get_xp(t_final_ray *ray)
{
	t_vect2d	ipv;
	float		xp;

	ipv = ft_scale_vect2d(ray->direction, ray->distance);
	ipv = ft_add_vect2d(ray->origin, ipv);
	if (ray->side == HORIZONTAL)
		xp = (ray->direction.y > 0) - (ipv.x - (int) ipv.x);
	if (ray->side == VERTICAL)
		xp = (ray->direction.x < 0) - (ipv.y - (int) ipv.y);
	return (fabs(xp));
}

//====<[ get_yp: ]>=============================================================
static float	get_yp(int32_t y, t_wall *wall)
{
	return ((y - wall->y_min) / (float) wall->height);
}

//====<[ get_texel: ]>==========================================================
static uint32_t	get_texel(float xp, float yp, mlx_texture_t *txtr, float intens)
{
	int			x;
	int			y;
	uint32_t	texel;

	if (!txtr)
		return (change_pixel_intensity(0xff0000ff, intens));
	x = xp * txtr->width;
	y = yp * txtr->height;
	texel = *((int32_t *) &txtr->pixels[(4 * y * txtr->width) + 4 * x]);
	return (change_pixel_intensity(texel, intens));
}

//====<[ maping_textures: ]>====================================================
void	maping_textures(mlx_image_t *view, int x, t_final_ray *r, t_data *data)
{
	t_wall		wall;
	uint32_t	pixel;
	float		xp;
	int32_t		y;
	double		c;

	get_wall_info(&wall, r, data);
	y = -1;
	c = 2 / wall.c;
	xp = get_xp(r);
	while (++y < WIN_HEIGHT)
	{
		if (y < wall.y_min)
			pixel = change_pixel_intensity(data->ceiling, (wall.y_moy - y) * c);
		else if (y >= wall.y_min && y < wall.y_max)
			pixel = get_texel(xp, get_yp(y, &wall), wall.txtr, wall.intensity);
		else
			pixel = change_pixel_intensity(data->floor, (y - wall.y_moy) * c);
		ft_memmove(&view->pixels[y * 4 * view->width + (x * 4)], &pixel, 4);
	}
}
