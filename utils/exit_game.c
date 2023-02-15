/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:14:34 by vpacheco          #+#    #+#             */
/*   Updated: 2023/01/11 15:05:39 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	print_error(int status, char *str, t_data *data)
{
	if (status)
		write(1, "Error\n", 6);
	ft_printf("%s\n", str);
	exit_game(data);
	return (0);
}

int	exit_game(t_data *data)
{
	int	i;

	i = 0;
	if (data->img)
	{
		while (data->img[i])
			mlx_destroy_image(data->mlx, data->img[i++]);
		free(data->img);
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free (map);
	}
}
