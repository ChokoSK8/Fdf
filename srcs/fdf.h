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
# define ABS(x) ((x) < 0 ? (-x):(x))

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

typedef struct	s_vect
{
	double		x;
	double		y;
}				t_vect;

typedef struct	s_line
{
	double	a;
	double	b;
}				t_line;

typedef struct	s_eraser
{
	t_line		a;
	t_line		b;
	t_ptdouble	pt_a;
	t_ptdouble	pt_c;
	t_ptdouble	pt_d;
}				t_eraser;

typedef struct	s_line_perp
{
	double		a;
	double		b;
	double		x_1;
	double		x_2;
}				t_line_perp;

typedef struct	s_param_perp
{
	t_line_perp		ab;
	t_line_perp		ac;
	t_line_perp		bd;
}				t_param_perp;

typedef struct	s_lines
{
	t_line	ab;
	t_line	ac;
	t_line	bd;
	t_line	cd;
}				t_lines;

typedef struct	s_display
{
	t_point		origin;
	t_vect		vect_x;
	t_vect		vect_y;
	double		angle;
}				t_display;

typedef struct	s_apex
{
	t_ptdouble	a;
	t_ptdouble	b;
	t_ptdouble	c;
	t_ptdouble	d;
}				t_apex;

typedef struct	s_map
{
	char		**data;
	int			**mati;
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
	double	coef_x;
	double	coef_y;
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

void	display_squares(t_img *img, t_ptdouble **mat_pos);

void	print_cases(t_img *img, t_point pt, int size_line);

void	print_diamonds(t_img *img,t_ptdouble **mat_pos, t_point pt, t_display disp);

char	*ft_strdup_fdf(const char *s1);

char	**ft_add_line_fdf(char **mat, char *line);

t_apex	get_apex_of_diamonds(t_apex apex, t_display disp);

t_vect		get_vect_btw_2_pts(t_ptdouble pt_a, t_ptdouble pt_b);

double		get_dist_btw_2_pts(t_ptdouble pt_a, t_ptdouble pt_b);

t_ptdouble	apply_vect(t_ptdouble pt, t_vect vect, double len);

double		get_coefxy(int coef_x, int coef_y);

void		print_apex(t_apex apex);

t_ptdouble	get_apex(t_display disp, t_ptdouble pt);

t_display	init_display(t_img img);

double		convert(double degre);

double		convert_inv(double rad);

void		display_line(t_ptdouble apex_a, t_ptdouble apex_b, int size_line, t_img *img);

t_ptdouble	**get_mat_pos(t_map map);

void		print_mat_pos(t_ptdouble **mat);

int			**ft_char_to_int_mat(char **matc, int max_width);

void		free_matc(char **matc);

void		free_mati(int **matc);

t_apex		get_apex_inside(t_apex apex);

void		print_inside_diamonds(t_img *img, t_apex apex);

int			is_pts_equal(t_ptdouble pt_a, t_ptdouble pt_b);

t_ptdouble	get_one_apex_inside(t_ptdouble pt_a, t_ptdouble pt_b);

t_apex		get_apex_biggest_line(t_apex apex);

t_ptdouble	get_pt_perpendiculare(t_lines lines, t_ptdouble pt);

t_lines		get_eq_lines(t_apex apex);

t_eraser	get_erasers(t_lines lines, t_apex apex);

double		get_angle_from_pts(t_ptdouble pt_a, t_ptdouble pt_b, t_ptdouble pt_c);

t_eraser	init_eraser(t_line line_a, t_line line_b, t_apex apex, int n);

t_vect		get_vect_from_line(t_line line);

void		erase_inside(t_apex apex, t_lines lines, t_img *img);

t_ptdouble	get_pt_perp(t_lines lines, t_ptdouble count, t_line eraser, t_apex apex);

t_param_perp		get_l_tmp(t_lines lines, t_line eraser, t_apex apex);

int		is_line_equal_to_eraser(t_line line, t_line eraser);

int		is_pt_between_x(double x_a, double x_b, double x_c);
#endif
