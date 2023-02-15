/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:22:42 by vpacheco          #+#    #+#             */
/*   Updated: 2023/02/15 16:51:47 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc != 2)
		print_error(1, "Wrong number of arguments", &data);
	parse(&data, argv);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (map_length(data.map) * 64), \
		(map_height(data.map) * 64), "Hello");
	render(&data);
	mlx_hook (data.win, 02, (1L << 0), key, &data);
	mlx_hook (data.win, 17, (1L << 2), exit_game, &data);
	mlx_loop_hook (data.mlx, animation, &data);
	mlx_loop (data.mlx);
}
