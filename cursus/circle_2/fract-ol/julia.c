#include "fractol.h"

int complex_squaring_J(t_set *set)
{
    set->x = set->complex_a;
    set->y = set->complex_b;
    set->k = 1;
    while (set->k <= ITERATION)
    {
        set->tmp = set->x;
        set->x = set->x * set->x - set->y * set->y + set->r1;
        set->y = 2 * set->tmp * set->y + set->r2;
        if (set->x * set->x + set->y * set->y > 4)
            break;
        set->k++;
    }
    return (set->k);
}

void random_complex(t_vars *vars)
{
    if (!vars->redraw)
    {
        vars->random_num = (vars->random_num * RANDOM_A + RANDOM_C) % RANDOM_M;
        vars->set->r1 = 4.0 * vars->random_num / RANDOM_MAX - 2.0;
        vars->set->r2 = 2.0 * vars->random_num / RANDOM_MAX - 1.0;
    }
}

void Julia(t_vars *vars, int count)
{
    while (count <= 1)
    {
        random_complex(vars);
        vars->set->i = 0;
        while (vars->set->i <= vars->img_height)
        {
            vars->set->complex_b = vars->max_height - (vars->set->i * (vars->max_height - vars->min_height) / vars->img_height);
            vars->set->j = 0;
            while (vars->set->j <= vars->img_width)
            {
                vars->set->complex_a = vars->min_width + (vars->set->j * (vars->max_width - vars->min_width) / vars->img_width);
                vars->set->k = complex_squaring_J(vars->set);
                if (vars->set->k == ITERATION + 1)
                {
                    mlx_pixel_put_on_image(vars->img, vars->set->j, vars->set->i, BLACK);
                    count++;
                }
                else
                    mlx_pixel_put_on_image(vars->img, vars->set->j, vars->set->i, create_rgb(vars));
                (vars->set->j)++;
            }
            (vars->set->i)++;
        }
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}