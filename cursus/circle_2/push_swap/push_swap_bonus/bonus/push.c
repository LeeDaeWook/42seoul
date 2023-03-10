#include "push_swap.h"

void push(t_deque *to, t_deque *from)
{
    t_node *temp;

    if (from->size == 0)
        return;
    temp = from->top->next;
    from->top->next = to->top;
    to->top = from->top;
    to->top->pre = NULL;
    from->top = temp;
    if (from->top)
        from->top->pre = NULL;
    if (to->top->next)
        to->top->next->pre = to->top;
    if (!to->size)
        to->bottom = to->top;
    (to->size)++;
    (from->size)--;
    if (!(from->size))
        ft_bzero((void*)from, sizeof(t_deque));
    compare_max_min(to);
    print_instructions(PUSH, to);
}

void compare_max_min(t_deque *to)
{
    if (!to->max && !to->min)
    {
        to->max = to->top;
        to->min = to->top;
    }
    else if (to->max && to->top->num > to->max->num)
        to->max = to->top;
    else if (to->min && to->top->num < to->min->num)
        to->min = to->top;
}
