#include "fractol.h"

// esc key press event
int key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
    {
        arrow_move(keycode, vars);
        redrawing(vars);
    }
    else if (keycode == 8)
    {
        vars->color_mul = (vars->color_mul * RANDOM_A + RANDOM_C) % (ITERATION + 1);
        vars->redraw = 1;
        redrawing(vars);
    }
    return (0);
}

void arrow_move(int keycode, t_vars *vars)
{
    double ax;
    double ay;

    ax = (vars->max_width - vars->min_width) / IMG_WIDTH;
    ay = (vars->max_height - vars->min_height) / IMG_HEIGHT;
    if (keycode == 123 || keycode == 124)
    {
        if (keycode == 123)
            ax *= -1;
        vars->min_width = vars->min_width + ax * MOVE_RATE;
        vars->max_width = vars->max_width + ax * MOVE_RATE;
    }
    else if (keycode == 125 || keycode == 126)
    {
        if (keycode == 125)
            ay *= -1;
        vars->min_height = vars->min_height + ay * MOVE_RATE;
        vars->max_height = vars->max_height + ay * MOVE_RATE;
    }
}