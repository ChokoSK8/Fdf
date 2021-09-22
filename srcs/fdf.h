#ifndef FDF_H

# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../Minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include "../Gnl/get_next_line.h"

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_ptdouble
{
	double		x;
	double		y;
}				t_ptdouble;

typedef struct	s_map
{
	char		**data;
	size_t		max_width;
	size_t		height;
}				t_map;

typedef struct	s_img
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	void	*image;
	int		coef_x;
	int		coef_y;
}				t_img;

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	size_t	width;
	size_t	height;
	t_img	img;
	t_map	map;
}				t_param;

int		ft_close_window(int key, t_param *param);

void	free_param(t_param *param);

int		init_map(t_map *map, char *file);

int		init_param(t_param *param, char *file);

void	init_param_len_and_coef(t_param *param);

void	display_squares(t_img *mg, t_map map);

void	print_cases(t_img *img, t_point pt, int size_line);

void	print_diamonds(t_img *img, t_point pt, int size_line);

char	*ft_strdup_fdf(const char *s1);

char	**ft_add_line_fdf(char **mat, char *line);
#endif
