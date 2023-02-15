/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:19:26 by vpacheco          #+#    #+#             */
/*   Updated: 2023/01/26 17:41:48 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	print_map(t_data *data, int index)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'X')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->img[index], \
				x * 64, y * 64);
			}
		}
	}
}

int	animation(void	*arg)
{
	t_data		*data;
	static int	frame;
	static int	e = 6;

	data = (t_data *)arg;
	frame++;
	if (frame == 50000)
	{
		print_map(data, e);
		e++;
		if (e == 8)
			e = 6;
		frame = 0;
	}
	return (0);
}
