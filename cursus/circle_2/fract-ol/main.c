#include "fractol.h"

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
    mlx_hook(vars.win, 17, 0, ft_exit, &vars);
    mlx_loop(vars.mlx);
    return (0);
}