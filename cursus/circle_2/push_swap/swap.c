#include "push_swap.h"

void    swap(t_deque *stack)
{
    t_node  *second_node;

    if (stack->size < 2)
    {
        ft_printf("at least 2 arguments needed\n");
        exit(EXIT_FAILURE);
    }
    second_node = stack->top->next;
    stack->top->next = second_node->next;
    second_node->next->pre = stack->top;
    second_node->next = stack->top;
    stack->top->pre = second_node;
    stack->top = second_node;
    stack->top->pre = NULL;
    print_instructions(SWAP, stack);
}
