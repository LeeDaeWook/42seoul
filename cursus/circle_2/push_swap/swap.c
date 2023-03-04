#include "push_swap.h"

void    swap(t_deque *deque, int stack_size)
{
    t_node  *second_node;

    if (stack_size < 2)
    {
        ft_printf("at least 2 arguments needed\n");
        exit(EXIT_FAILURE);
    }
    second_node = deque->top->next;
    deque->top->next = second_node->next;
    second_node->next = deque->top;
    deque->top->pre = second_node;
    deque->top = second_node;
    deque->top->pre = NULL;
}

// void    sa(t_node **head, int stack_size)
// {
//     t_node  *second_node;

//     if (stack_size < 2)
//     {
//         ft_printf("at least 2 arguments needed\n");
//         exit(EXIT_FAILURE);
//     }
//     second_node = (*head)->next;
//     (*head)->next = second_node->next;
//     second_node->next = *head;
//     *head = second_node;
// }

// void    sb(t_node **head, int stack_size)
// {
//     t_node  *second_node;

//     if (stack_size < 2)
//     {
//         ft_printf("at least 2 arguments needed\n");
//         exit(EXIT_FAILURE);
//     }
//     second_node = (*head)->next;
//     (*head)->next = second_node->next;
//     second_node->next = *head;
//     *head = second_node;
// }

// void    ss(t_node **head, int stack_size)
// {
//     sa(head, stack_size);
//     sb(head, stack_size);
// }
