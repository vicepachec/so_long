/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:44:48 by vpacheco          #+#    #+#             */
/*   Updated: 2023/02/15 16:15:09 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	parse(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		print_error(1, "It's a directory", data);
	}
	fd = open(argv[1], O_RDONLY);
	data->map = map_to_string(NULL, fd, 0, data);
	close(fd);
	check_letter(data);
	if (!border_check(data))
		print_error(1, "Map is not closed", data);
	path_valid(data->map, 0, 0, data);
	return (0);
}
