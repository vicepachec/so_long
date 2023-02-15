/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:31:36 by vpacheco          #+#    #+#             */
/*   Updated: 2023/01/26 17:32:13 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	load_image(t_data	*data)
{
	int	i;

	i = 64;
	data->img = malloc(9 * sizeof(void *));
	if (!data->img)
		return ;
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "./assets/floor.xpm", \
	&i, &i);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "./assets/tree.xpm", \
	&i, &i);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "./assets/player.xpm", \
	&i, &i);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "./assets/gold_1.xpm", \
	&i, &i);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "./assets/exit.xpm", \
	&i, &i);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, "./assets/exit2.xpm", \
	&i, &i);
	data->img[6] = mlx_xpm_file_to_image(data->mlx, "./assets/enemy.xpm", \
	&i, &i);
	data->img[7] = mlx_xpm_file_to_image(data->mlx, "./assets/enemy2.xpm", \
	&i, &i);
	data->img[8] = NULL;
}

static void	render_image(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img[0], \
		x * 64, y * 64);
	if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img[4], \
		x * 64, y * 64);
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img[1], \
		x * 64, y * 64);
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img[2], \
		x * 64, y * 64);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img[3], \
		x * 64, y * 64);
	if (data->map[y][x] == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->img[6], \
		x * 64, y * 64);
}

void	render(t_data *data)
{
	int	y;
	int	x;

	load_image(data);
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			render_image(data, x, y);
		}
	}
}
