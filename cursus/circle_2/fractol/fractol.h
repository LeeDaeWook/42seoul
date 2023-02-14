/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:48:42 by daewoole          #+#    #+#             */
/*   Updated: 2023/02/14 10:08:09 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define W_WIDTH 800
# define W_HEIGHT 800
# define IMG_WIDTH 800
# define IMG_HEIGHT 800

# define ITERATION 255
# define MOVE_RATE 10
# define COLOR_MUL 10

# define MAX_WIDTH 2
# define MAX_HEIGHT 2
# define MIN_WIDTH -2
# define MIN_HEIGHT -2

# define RANDOM_MAX 2147483647
# define RANDOM_SEED 10
# define RANDOM_A 1103515245
# define RANDOM_C 12345
# define RANDOM_M 2147483648

# define BLACK 0x00000000
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ZOOM_RATE 0.5

# define ESC_KEY 53
# define C_KEY 8
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_set
{
	double	x;
	double	y;
	double	complex_a;
	double	complex_b;
	double	tmp;
	double	r1;
	double	r2;
	int		i;
	int		j;
	int		k;
}	t_set;

typedef struct s_vars
{
	t_img	*img;
	t_set	*set;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		button;
	double	img_width;
	double	img_height;
	double	max_width;
	double	min_width;
	double	max_height;
	double	min_height;
	char	which_set;
	size_t	random_num;
	size_t	color_mul;
	size_t	redraw;
}	t_vars;

void	mlx_pixel_put_on_image(t_img *img, int x, int y, int color);
int		key_hook(int keycode, t_vars *vars);
void	arrow_move(int keycode, t_vars *vars);
int		create_rgb(t_vars *vars);
void	redrawing(t_vars *vars);
int		mouse_zoom(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		complex_squaring_M(t_set *set);
void	mandelbrot(t_vars *vars);
int		complex_squaring_j(t_set *set);
void	random_complex(t_vars *vars);
void	put_pixel_j(t_vars *vars, int *count);
void	julia(t_vars *vars);
int		complex_squaring_b(t_set *set);
void	burningship(t_vars *vars);
int		ft_exit(t_vars *vars);
void	print_list(void);
int		validate_param(int argc, char *argv[], t_vars *vars);
void	initializing(t_img *img, t_vars *vars, t_set *set);
void	into_fractal(int argc, char *argv[], t_vars *vars);
int		main(int argc, char *argv[]);

#endif
