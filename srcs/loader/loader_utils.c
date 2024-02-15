/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:16:52 by oezzaou           #+#    #+#             */
/*   Updated: 2023/10/24 18:52:46 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//====< get_line >==============================================================
char	*get_line(int fd, int index)
{
	char	*tmp;
	char	c;

	if (!read(fd, &c, 1) || c == '\n')
		return (ft_calloc((index + 1) * !(!index && c != '\n'), 1));
	tmp = get_line(fd, index + 1);
	if (tmp)
		tmp[index] = c;
	return (tmp);
}

//==== tokenizer :=============================================================
t_token	tokenizer(char *line)
{
	t_token	token;

	while (line && *line && *line == ' ')
		line++;
	token.key = line;
	while (line && *line && *line != ' ')
		line++;
	if (line != NULL && *line != '\0')
		*line++ = '\0';
	while (line && *line && *line == ' ')
		line++;
	token.value = line;
	return (token);
}

//====< check_unit >===========================================================
bool	check_unit(char **map, int row, int colum)
{
	if (!ft_strchr(" 012NSWE", map[row][colum]))
		return (false);
	if (!row || !colum || !map[row + 1] || !map[row][colum + 1])
		return (false);
	else if (map[row][colum - 1] == ' ' || map[row][colum + 1] == ' ')
		return (false);
	else if (ft_strlen(map[row - 1]) < colum + 1
		|| ft_strlen(map[row + 1]) < colum + 1)
		return (false);
	else if (map[row - 1][colum] == ' ' || map[row + 1][colum] == ' ')
		return (false);
	return (true);
}

//====< clean_data >============================================================
void	*clean_data(t_data *data)
{
	int	i;

	i = -1;
	if (data == NULL)
		return (NULL);
	if (data->door != NULL)
		mlx_delete_texture(data->door);
	while (++i < 4)
	{
		if (data->wall[i])
			mlx_delete_texture(data->wall[i]);
	}
	i = -1;
	while (data->map && data->map[++i])
		free(data->map[i]);
	free(data->map);
	return (NULL);
}
