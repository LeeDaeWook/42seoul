#include "push_swap.h"

void    swap(t_deque *deque)
{
    t_node  *second_node;

    if (deque->size < 2)
    {
        ft_printf("at least 2 arguments needed\n");
        exit(EXIT_FAILURE);
    }
    second_node = deque->top->next;
    deque->top->next = second_node->next;
    second_node->next->pre = deque->top;
    second_node->next = deque->top;
    deque->top->pre = second_node;
    deque->top = second_node;
    deque->top->pre = NULL;
    print_instructions(SWAP, deque);
}
