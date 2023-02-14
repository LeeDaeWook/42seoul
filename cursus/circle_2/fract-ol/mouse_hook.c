#include "fractol.h"

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
    redrawing(vars);
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
        vars->redraw = 1;
        mouse_zoom(vars);
    }
    // mouse_zoom(vars); // 여기를 활성화해놓고 위의 조건문의 mouse_zoom을 주석처리하면 마우스 왼쪽 혹은 오른쪽 클릭 시 julia set(물론 mandelbrot도)을 다시 그림
    return (0);
}