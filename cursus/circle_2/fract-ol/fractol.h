
#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
// # include "libft/libft.h"
# include "mlx/mlx.h"

# define W_WIDTH 800
# define W_HEIGHT 800
# define IMG_WIDTH 800
# define IMG_HEIGHT 800

# define ITERATION 255
# define MOVE_RATE 10
# define COLOR_MUL 10

# define MAX_WIDTH 2 // 여기서부터 4개의 값은 좌표상의 x축 최대, 최소값과 y축 최대, 최소값을 의미
# define MAX_HEIGHT 2
# define MIN_WIDTH -2
# define MIN_HEIGHT -2

# define RANDOM_MAX 2147483647
# define RANDOM_SEED 10
# define RANDOM_A 1103515245 // ANSI C standard
# define RANDOM_C 12345
# define RANDOM_M 2147483648

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
    void    *mlx;
    void    *win;
    int     x;
    int     y;
    int     button;
    double  img_width;
    double  img_height;
    double  max_width;
    double  min_width;
    double  max_height;
    double  min_height;
    char    which_set;
    unsigned int    random_num;
    unsigned int    color_mul;
    unsigned int    redraw;
} t_vars;

void    mlx_pixel_put_on_image(t_img *img, int x, int y, int color);
int     key_hook(int keycode, t_vars *vars);
void    arrow_move(int keycode, t_vars *vars);
int     create_rgb(t_vars *vars);
void    redrawing(t_vars *vars);
int     mouse_zoom(t_vars *vars);
int     mouse_hook(int button, int x, int y, t_vars *vars);
int     complex_squaring_M(t_set *set);
void    Mandelbrot(t_vars *vars);
int     complex_squaring_J(t_set *set);
void    random_complex(t_vars *vars);
void    Julia(t_vars *vars, int count);
int     complex_squaring_B(t_set *set);
void    Burningship(t_vars *vars);
int     ft_exit(t_vars *vars);
int     validate_param(int argc, char *argv[], t_vars *vars);
void    initializing(t_img *img, t_vars *vars, t_set *set);
void    into_fractal(int argc, char *argv[], t_vars *vars);
int     main(int argc, char *argv[]);

#endif