/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:26:07 by vpacheco          #+#    #+#             */
/*   Updated: 2023/01/26 17:49:10 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "get_next_line.h"
# include <fcntl.h>
# include "../ft_printf/includes/ft_printf.h"

# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	void	**img;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		col;
	int		player_count;
	int		exit_count;
}t_data;

int		key(int keycode, void *param, t_data *data);
int		exit_game(t_data *data);
char	**map_to_string(char **map, int fd, int i, t_data *data);
void	load_image(t_data	*data);
int		map_length(char **map);
int		map_height(char **map);
void	render(t_data *data);
char	*ft_itoa(int n);
int		check_mov(t_data *data, int x, int y);
void	coord(int x, int y, t_data *data);
int		print_error(int status, char *str, t_data *data);
int		check_valid(t_data *data, char *str, int counter);
int		check_letter(t_data *data);
int		border_check(t_data *data);
int		path_valid(char **cpy, int y, int x, t_data *data);
void	check_path(char **cpy, int y, int x);
char	**map_cpy(char **cpy, t_data *data);
void	free_map(char **map);
int		animation(void	*arg);
int		parse(t_data *data, char **argv);

#endif