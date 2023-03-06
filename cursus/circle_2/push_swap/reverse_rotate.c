#include "push_swap.h"

void reverse_rotate(t_deque *deque)
{
    t_node *original_top;
    t_node *original_bottom;

    original_top = deque->top;
    original_bottom = deque->bottom;
    original_top->pre = original_bottom;
    original_bottom->next = original_top;
    deque->bottom = original_bottom->pre;
    deque->bottom->next = NULL;
    deque->top = original_bottom;
    deque->top->pre = NULL;
}
