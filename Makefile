NAME		= fdf

LIB_MLX		= libmlx.a

SRCS		= srcs/main.c srcs/close_window.c srcs/free_param.c srcs/free_param_2.c srcs/init_param.c srcs/init_param_utils.c srcs/display.c srcs/get_mat_pos.c srcs/char_to_double.c srcs/char_to_double_utils.c srcs/erase_inside.c srcs/print_diamonds_utils.c srcs/get_pt_perp.c srcs/get_pt_perp_utils.c srcs/tools.c srcs/tools_2.c srcs/tools_3.c srcs/init_map.c srcs/init_map_2.c

MLX_SRCS	= Mlx_fcts/mlx_shaders.c Mlx_fcts/mlx_new_window.m Mlx_fcts/mlx_init_loop.m Mlx_fcts/mlx_new_image.m Mlx_fcts/mlx_xpm.c Mlx_fcts/mlx_int_str_to_wordtab.c

OBJS		= $(SRCS:.c=.o)

MLX_OBJS	= $(MLX_SRCS:.c=.o)

MLX_OBJS_M	= $(MLX_OBJS:.m=.o)

FLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

INC			= -I includes/ -Imlx

%.o: %.c
			cc $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

$(LIB_MLX):		$(MLX_OBJS)
			ar -r $(LIB_MLX) $(MLX_OBJS)
			ranlib $(LIB_MLX)

lib:
		make -C Libft

mlx_t:
		make -C Minilibx-linux

$(NAME): lib mlx_t $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz Libft/libft.a Minilibx-linux/$(LIB_MLX) -o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C Libft
		make clean -C Minilibx-linux

fclean:		clean
			$(RM) $(NAME)
			make fclean -C Libft

re:			fclean all

.PHONY:		all clean fclean re
