#include "fractol.h"

void mlx_pixel_put_on_image(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

// esc key press event
int key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}

int create_rgb(int color)
{
    color = (int)log2(color) * 10;
    return ((color * 3) << 16 | (color * 5) << 8 | (color * 3));
}

void redrawing_set(t_vars *vars)
{
    mlx_clear_window(vars->mlx, vars->win);
    if (vars->which_set == 'm')
        Mandelbrot(vars);
    else if (vars->which_set == 'j')
        Julia(vars, 0);
}

int mouse_zoom(t_vars *vars)
{
    double ax;
    double ay;

    ax = (vars->max_width - vars->min_width) / IMG_WIDTH;
    ay = (vars->max_height - vars->min_height) / IMG_HEIGHT;
    if (vars->button == SCROLL_DOWN) // 확대
    {
        vars->min_width = (vars->min_width + (ax * vars->x * ZOOM_RATE));
        vars->max_width = (vars->max_width - (ax * (IMG_WIDTH - vars->x) * ZOOM_RATE));
        vars->max_height = (vars->max_height - (ay * vars->y * ZOOM_RATE));
        vars->min_height = (vars->min_height + (ay * (IMG_HEIGHT - vars->y) * ZOOM_RATE));
    }
    else if (vars->button == SCROLL_UP)
    {
        vars->min_width = vars->min_width - ZOOM_RATE;
        vars->max_width = vars->max_width + ZOOM_RATE;
        vars->max_height = vars->max_height + ZOOM_RATE;
        vars->min_height = vars->min_height - ZOOM_RATE;
    }
    redrawing_set(vars);
    return (0);
}

// 마우스 버튼 번호 : 왼쪽 버튼 = 1번, 오른쪽 버튼 = 2번, 아래로 휠 = 5번, 위로 휠 = 4번
int mouse_hook(int button, int x, int y, t_vars *vars)
{
    if (button == SCROLL_UP || button == SCROLL_DOWN)
    {
        vars->button = button;
        vars->x = x;
        vars->y = y;
        mouse_zoom(vars);
    }
    // mouse_zoom(vars); // 여기를 활성화해놓고 위의 조건문의 mouse_zoom을 주석처리하면 마우스 왼쪽 혹은 오른쪽 클릭 시 julia set(물론 mandelbrot도)을 다시 그림
    return (0);
}

int complex_squaring_M(t_set *set)
{
    set->x = 0;
    set->y = 0;
    set->k = 0;
    while (set->k <= 255)
    {
        set->tmp = set->x;
        set->x = set->x * set->x - set->y * set->y + set->complex_a;
        set->y = 2 * set->tmp * set->y + set->complex_b;
        if (set->x * set->x + set->y * set->y > 4)
            break;
        set->k++;
    }
    return (set->k);
}

// 점화식 Z_n+1 = Z_n^2 + c;
void Mandelbrot(t_vars *vars)
{
    vars->set->i = 0;
    while (vars->set->i <= vars->img_height)
    {
        vars->set->complex_b = vars->max_height - (vars->set->i * (vars->max_height - vars->min_height) / vars->img_height);
        vars->set->j = 0;
        while (vars->set->j <= vars->img_width)
        {
            vars->set->complex_a = vars->min_width + (vars->set->j * (vars->max_width - vars->min_width) / vars->img_width);
            vars->set->k = complex_squaring_M(vars->set);
            if (vars->set->k == 256)
                mlx_pixel_put_on_image(vars->img, vars->set->j, vars->set->i, BLACK);
            else
                mlx_pixel_put_on_image(vars->img, vars->set->j, vars->set->i, create_rgb(vars->set->k));
            (vars->set->j)++;
        }
        (vars->set->i)++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

int complex_squaring_J(t_set *set)
{
    set->x = set->complex_a;
    set->y = set->complex_b;
    set->k = 1;
    while (set->k <= 255)
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
    if (vars->button != SCROLL_DOWN && vars->button != SCROLL_UP)
    {
        vars->set->r1 = 4.0 * rand() / RAND_MAX - 2.0;
        vars->set->r2 = 2.0 * rand() / RAND_MAX - 1.0;
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
                if (vars->set->k == 256)
                {
                    mlx_pixel_put_on_image(vars->img, vars->set->j, vars->set->i, BLACK);
                    count++;
                }
                else
                    mlx_pixel_put_on_image(vars->img, vars->set->j, vars->set->i, create_rgb(vars->set->k));
                (vars->set->j)++;
            }
            (vars->set->i)++;
        }
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
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
    else
    {
        printf("Availiable fractal set list\n");
        printf("-> Mandelbrot Set\n");
        printf("-> Julia Set\n");
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
}

void into_fractal(int argc, char *argv[], t_vars *vars)
{
    if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")))
    {
        vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "Mandelbrot Set");
        Mandelbrot(vars);
    }
    else if (!ft_strncmp(argv[1], "Julia", ft_strlen("Julia")))
    {
        if (argc == 3)
            srand(ft_atoi(argv[2])); // julia set의 complex number를 random하게 정하기 위해서
                                     // -> srand와 rand함수는 math.h의 함수가 아니어서 못씀, 추후 교체 필요
        vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "Julia Set");
        Julia(vars, 0);
    }
}

int main(int argc, char *argv[])
{
    t_img img;
    t_vars vars;
    t_set set;

    if (!validate_param(argc, argv, &vars)) // parameter가 없거나 invalid한 경우
        exit(0);
    vars.mlx = mlx_init(); // (screen connection identifier) 현재 소프트웨어와 디스플레이 장치와의 연결에 대한 식별자를 void *로 반환, 실패시 null 반환
    img.img = mlx_new_image(vars.mlx, W_WIDTH, W_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    initializing(&img, &vars, &set);
    into_fractal(argc, argv, &vars);
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
    return (0);
}

// int create_rgb(int color)
// {
//     double  r;
//     double  g;
//     double  b;

//     r = log2(0.3 * (double)color);
//     g = log2(0.3 * (double)color + 3) * 127;
//     b = log2(0.3 * (double)color + 3) * 127 + 128;
//     color = ((int)(255 * r) << 16) + ((int)(255 * g) << 8) + ((int)(255 * b));
//     return (color);
// }

// int    mouse_zoom(t_vars *vars)
// {
//     if (vars->button == SCROLL_UP)
//     {
//         vars->max_width -= ZOOM_RATE * ((vars->img_width - vars->x) / vars->img_width);
//         vars->min_width += ZOOM_RATE * (vars->x / vars->img_width);
//         vars->max_height -= ZOOM_RATE * ((vars->img_height - vars->y) / vars->img_height);
//         vars->min_height += ZOOM_RATE * (vars->y / vars->img_height);
//     }
//     else if (vars->button == SCROLL_DOWN)
//     {
//         vars->max_width += ZOOM_RATE * ((vars->img_width - vars->x) / vars->img_width);
//         vars->min_width -= ZOOM_RATE * (vars->x / vars->img_width);
//         vars->max_height += ZOOM_RATE * ((vars->img_height - vars->y) / vars->img_height);
//         vars->min_height -= ZOOM_RATE * (vars->y / vars->img_height);
//     }
//     else
//         return (0);
//     vars->img_width = vars->max_width - vars->min_width;
//     vars->img_height = vars->max_height - vars->min_height;
//     redrawing_set(vars);
//     return (0);
// }