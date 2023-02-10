
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

# define MAX_WIDTH 2 // 여기서부터 4개의 값은 좌표상의 x축 최대, 최소값과 y축 최대, 최소값을 의미
# define MAX_HEIGHT 2
# define MIN_WIDTH -2
# define MIN_HEIGHT -2

# define BLACK 0x00000000
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ZOOM_RATE 0.5

typedef struct s_img
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_img;

typedef struct s_set
{
    double x; // Z = x + yi
    double y;
    double complex_a; // C = a + bi
    double complex_b;
    double tmp;
    double r1; // julia set을 위한 random complex number
    double r2;
    int i;
    int j;
    int k;
} t_set;

typedef struct s_vars
{
    t_img   *img;
    t_set   *set;
    void *mlx;
    void *win;
    int x;
    int y;
    int button;
    double  img_width;
    double  img_height;
    double  max_width;
    double  min_width;
    double  max_height;
    double  min_height;
    char    which_set;
} t_vars;

void    mlx_pixel_put_on_image(t_img *img, int x, int y, int color);
int     key_hook(int keycode, t_vars *vars);
int     create_rgb(int color);
void    redrawing_set(t_vars *vars);
int     mouse_zoom(t_vars *vars);
int     mouse_hook(int button, int x, int y, t_vars *vars);
int     complex_squaring_M(t_set *set);
void    Mandelbrot(t_vars *vars);
int     complex_squaring_J(t_set *set);
void    Julia(t_vars *vars, int count);
int     validate_param(int argc, char *argv[], t_vars *vars);
void    initializing(t_img *img, t_vars *vars, t_set *set);
void    into_fractal(int argc, char *argv[], t_vars *vars);
int     main(int argc, char *argv[]);

#endif