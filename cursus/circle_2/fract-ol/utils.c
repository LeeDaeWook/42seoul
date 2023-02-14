#include "fractol.h"

int ft_exit(t_vars *vars)
{
    (void) vars;
    exit(0);
}

int validate_param(int argc, char *argv[], t_vars *vars)
{
    if (argc == 2 && (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot"))))
    {
        vars->which_set = 'm';
        return (1);
    }
    else if ((argc == 2 && !ft_strncmp(argv[1], "Julia", ft_strlen("Julia"))) || (argc == 3 && !ft_strncmp(argv[1], "Julia", ft_strlen("Julia"))))
    {
        vars->which_set = 'j';
        return (1);
    }
    else if (argc == 2 && !ft_strncmp(argv[1], "Burningship", ft_strlen("Burningship")))
    {
        vars->which_set = 'b';
        return (1);
    }
    else
    {
        printf("Availiable fractal list\n");
        printf("-> Mandelbrot Set\n");
        printf("-> Julia Set\n");
        printf("-> Burning ship");
        return (0);
    }
}

void initializing(t_img *img, t_vars *vars, t_set *set)
{
    vars->img_width = IMG_WIDTH;
    vars->img_height = IMG_HEIGHT;
    vars->img = img;
    vars->set = set;
    vars->max_width = MAX_WIDTH;
    vars->min_width = MIN_WIDTH;
    vars->max_height = MAX_HEIGHT;
    vars->min_height = MIN_HEIGHT;
    vars->color_mul = COLOR_MUL;
    vars->redraw = 0;
}

void into_fractal(int argc, char *argv[], t_vars *vars)
{
    if (vars->which_set == 'm')
    {
        vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "Mandelbrot Set");
        Mandelbrot(vars);
    }
    else if (vars->which_set == 'j')
    {
        if (argc == 2)
            vars->random_num = RANDOM_SEED;
        else if (argc == 3)
            vars->random_num = (unsigned int)ft_atoi(argv[2]);
        vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "Julia Set");
        Julia(vars, 0);
    }
    else if (vars->which_set == 'b')
    {
        vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "Burning ship");
        Burningship(vars);
    }
}