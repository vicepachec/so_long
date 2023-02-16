SRCS	=	main.c \
			utils/move.c \
			utils/exit_game.c \
			utils/map_to_string.c\
			utils/get_next_line.c\
			utils/get_next_line_utils.c\
			utils/load_image.c\
			utils/utils.c\
			utils/check_path.c\
			utils/animation.c\
			utils/parse.c\

OBJS	= $(SRCS:.c=.o)

NAME	= so_long

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

RM		= rm -rf

MLX		=	mlx_linux/libmlx_Linux.a

FT_PRINTF = ft_printf/libftprintf.a

MLX_LIB_DIR = mlx_linux/

MLX_INCLUDE = -Imlx_linux

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(FT_PRINTF)
		$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@

$(MLX):
		make -C mlx_linux

$(FT_PRINTF):
		make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX_INCLUDE) -c $^ -o $@


clean: 
	$(RM) $(OBJS)
	make clean -C mlx_linux
	make clean -C ft_printf

fclean: clean
		$(RM) $(NAME) $(OBJS)
		make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re