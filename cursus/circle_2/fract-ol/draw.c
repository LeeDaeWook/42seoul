#include "fractol.h"

void mlx_pixel_put_on_image(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int create_rgb(t_vars *vars)
{
    int color;

    color = sin(vars->set->k) * vars->color_mul;
    if (color < 0)
        color *= -1;
    // return ((vars->set->k * 15 % (ITERATION + 1)) << 24 | 255 << 16 | ((vars->set->k * 7) % (ITERATION + 1)) << 8 | 0);
    return (((color * 3) % (ITERATION + 1)) << 16 | ((color * 5) % (ITERATION + 1)) << 8 | (color % (ITERATION + 1)));
}

void redrawing(t_vars *vars)
{
    mlx_clear_window(vars->mlx, vars->win);
    if (vars->which_set == 'm')
        Mandelbrot(vars);
    else if (vars->which_set == 'j')
        Julia(vars, 0);
    else if (vars->which_set == 'b')
        Burningship(vars);
}