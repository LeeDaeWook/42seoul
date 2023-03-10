#include "push_swap.h"

void rotate(t_deque *deque, int idx)
{
    t_node *original_top;
    t_node *original_bottom;

    original_top = deque->top;
    original_bottom = deque->bottom;
    original_bottom->next = original_top;
    deque->top = original_top->next;
    deque->top->pre = NULL;
    deque->bottom = original_top;
    deque->bottom->pre = original_bottom;
    deque->bottom->next = NULL;
    if (idx != RR && idx != RRR)
        print_instructions(idx, NULL);
}

