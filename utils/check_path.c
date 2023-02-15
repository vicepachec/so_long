/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:08:30 by vpacheco          #+#    #+#             */
/*   Updated: 2023/02/15 16:02:05 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**map_cpy(char **cpy, t_data *data)
{
	char	**temp;
	int		i;

	temp = malloc(sizeof(char *) * (map_height(data->map) + 1));
	if (!temp)
		print_error(1, "Can't allocate copy", data);
	i = -1;
	while (cpy[++i])
	{
		temp[i] = ft_strdup(cpy[i]);
		if (!temp[i])
			print_error(1, "Error while copying malloc", data);
	}
	temp[i] = NULL;
	return (temp);
}

void	check_path(char **cpy, int y, int x)
{
	cpy[y][x] = 'P';
	if (cpy[y - 1][x] == 'C' || cpy[y - 1][x] == '0')
		check_path(cpy, y - 1, x);
	if (cpy[y][x - 1] == 'C' || cpy[y][x - 1] == '0')
		check_path(cpy, y, x - 1);
	if (cpy[y + 1][x] == 'C' || cpy[y + 1][x] == '0')
		check_path(cpy, y + 1, x);
	if (cpy[y][x + 1] == 'C' || cpy[y][x + 1] == '0')
		check_path(cpy, y, x + 1);
}

int	path_valid(char **cpy, int y, int x, t_data *data)
{
	char	**temp;

	temp = map_cpy(cpy, data);
	check_path(temp, data->player_y / 64, data->player_x / 64);
	y = -1;
	while (temp[++y])
	{
		x = -1;
		while (temp[y][++x])
		{
			if (temp[y][x] == 'C')
			{
				free_map(temp);
				print_error(1, "Path is not valid", data);
			}
			if (temp[y][x] == 'E' && (!(temp[y - 1][x] == 'P' || temp [y + 1] \
				[x] == 'P' || temp[y][x - 1] == 'P' || temp[y][x + 1] == 'P')))
			{
				free_map(temp);
				print_error(1, "Path is not valid", data);
			}
		}
	}
	free_map(temp);
	return (0);
}

int	check_letter(t_data *data)
{
	if (data->player_count != 1)
		print_error(1, "Wrong number of players", data);
	if (data->exit_count != 1)
		print_error(1, "Wrong number of exits", data);
	if (data->col < 1)
		print_error(1, "There is no collectibles", data);
	return (0);
}
