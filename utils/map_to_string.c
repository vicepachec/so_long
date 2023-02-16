/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:39:43 by vpacheco          #+#    #+#             */
/*   Updated: 2023/02/16 15:49:10 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**map_to_string(char **map, int fd, int i, t_data *data)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
	{
		check_valid(data, str, i);
		map = map_to_string(map, fd, i + 1, data);
	}
	if (!map && i != 0)
		map = malloc((i + 1) * sizeof(char *));
	if (!map)
		return (0);
	map[i] = str;
	return (map);
}

int	map_length(char **map)
{
	int	x;

	x = 0;
	while (map[0][x] && map[0][x] != '\n')
		x++;
	return (x);
}

int	map_height(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	border_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < map_length(data->map))
	{
		if (data->map[0][i] != '1' || data->map[map_height(data->map) \
			- 1][i] != '1')
			return (0);
		i++;
	}	
	i = 1;
	while (i < map_height(data->map))
	{
		if (data->map[0][0] != '1')
			print_error(1, "Invalid map", data);
		if (data->map[i][0] != '1' || data->map[i][map_length(data->map) \
			- 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
