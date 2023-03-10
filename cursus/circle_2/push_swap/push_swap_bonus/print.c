#include "push_swap.h"

void print_instructions(int flag, t_deque *stack)
{
    if (stack && flag == SWAP && stack->stack == STACK_A)
        ft_printf("sa\n");
    else if (stack && flag == SWAP && stack->stack == STACK_B)
        ft_printf("sb\n");
    else if (stack && flag == PUSH && stack->stack == STACK_A)
        ft_printf("pa\n");
    else if (stack && flag == PUSH && stack->stack == STACK_B)
        ft_printf("pb\n");
    else if (!stack && flag == RA)
        ft_printf("ra\n");
    else if (!stack && flag == RB)
        ft_printf("rb\n");
    else if (!stack && flag == RRA)
        ft_printf("rra\n");
    else if (!stack && flag == RRB)
        ft_printf("rrb\n");
    else if (!stack && flag == RR)
        ft_printf("rr\n");
    else if (!stack && flag == RRR)
        ft_printf("rrr\n");
}
