/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:27:31 by oezzaou           #+#    #+#             */
/*   Updated: 2023/10/24 20:33:29 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//====< read_map >==============================================================
static char	**read_map(int fd, char *line, int index)
{
	char	**map;
	char	*cur_line;

	cur_line = get_line(fd, 0);
	if (line == NULL)
		return (ft_calloc((index + 1) * !!index, sizeof(char *)));
	map = read_map(fd, cur_line, index + 1);
	if (!map)
		return (free(line), NULL);
	map[index] = line;
	return (map);
}

//====< check_map >=============================================================
static bool	check_map(char **map, t_data *data)
{
	int		row;
	int		colum;

	row = 0;
	while (row < 4 && data->wall[row])
		row++;
	if (row < 4)
		return (ft_perror("Invalid Textures"), false);
	if (data->floor <= 1 || data->ceiling <= 1)
		return (ft_perror("Invalid color"), false);
	row = -1;
	while (map && map[++row] && *map[row])
	{
		colum = -1;
		while (map[row][++colum])
		{
			if (!ft_strchr(" 1", map[row][colum])
				&& !check_unit(map, row, colum))
				return (false);
		}
	}
	data->height = row;
	return (map && map[row] == NULL);
}

//====< is_map >================================================================
static bool	is_map(char *line)
{
	int	index;

	index = 0;
	if (line == NULL)
		return (true);
	while (line[index] && ft_strchr(" 012NSEW", line[index]))
		index++;
	return (index && line[index] == '\0');
}

//==== is_cub_map :=============================================================
static bool	is_cub_map(char const *file)
{
	int	len;

	len = ft_strlen(file);
	if (len > 4 && ft_strcmp(&file[len - 4], ".cub") == 0)
		return (true);
	ft_perror("expected .cub file!!");
	return (false);
}

//===< loader >=================================================================
t_data	*loader(char const *file)
{
	t_data	*data;
	int		fd;
	char	*line;

	data = ft_calloc(1, sizeof(t_data));
	fd = open(file, O_RDONLY);
	if (!is_cub_map(file) || data == NULL || fd < 0)
		return (ft_perror("Invalid file"), free(data), close(fd), NULL);
	data->prespective = WIN_HEIGHT / 2;
	line = get_line(fd, 0);
	while (is_map(line) == false)
	{
		if (*line && load_assets(line, data) == false)
			return (free(line), close(fd), clean_data(data));
		free(line);
		line = get_line(fd, 0);
	}
	data->map = read_map(fd, line, 0);
	if (check_map(data->map, data) == false)
		return (ft_perror("Invalid Map"), close(fd), clean_data(data));
	return (close(fd), data);
}
