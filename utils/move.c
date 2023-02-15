/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:07:05 by vpacheco          #+#    #+#             */
/*   Updated: 2023/01/26 16:42:01 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static	int	player_mov(int keycode, t_data *data)
{
	static int	step = 0;
	char		*str;

	mlx_put_image_to_window(data->mlx, data->win, data->img[0], \
	data->player_x, data->player_y);
	data->map[data->player_y / 64][data->player_x / 64] = '0';
	data->player_x += (((keycode == D) - (keycode == A)) * 64);
	data->player_y += (((keycode == S) - (keycode == W)) * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->img[2], \
	data->player_x, data->player_y);
	data->map[data->player_y / 64][data->player_x / 64] = 'P';
	step++;
	str = ft_itoa(step);
	mlx_put_image_to_window(data->mlx, data->win, data->img[1], 0, 0);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, str);
	free(str);
	return (0);
}

int	check_mov(t_data *data, int x, int y)
{	
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'E' && data->col > 0)
		ft_printf("Bro go collect the rest of the coins\n");
	if (data->map[y][x] == 'E')
	{
		if (data->col == 0)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img[5], \
			x * 64, y * 64);
			print_error(0, "You found the exit", data);
		}
		return (0);
	}
	if (data->map[y][x] == 'C')
		data->col--;
	if (data->map[y][x] == 'X')
		print_error(0, "You just got slimed", data);
	return (1);
}

int	key(int keycode, void *param, t_data *data)
{
	int	x;
	int	y;

	data = param;
	if (keycode == 65307)
		exit_game(data);
	if (!(keycode == W || keycode == A || keycode == S || keycode == D))
		return (1);
	x = data->player_x / 64 + ((keycode == D) - (keycode == A));
	y = data->player_y / 64 + ((keycode == S) - (keycode == W));
	if (check_mov(data, x, y))
		player_mov(keycode, data);
	return (0);
}
