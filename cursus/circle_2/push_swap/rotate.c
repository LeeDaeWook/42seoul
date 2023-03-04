#include "push_swap.h"

void rotate(t_deque *deque)
{
    t_node *original_top;
    t_node *original_bottom;

    original_top = deque->top;
    original_bottom = deque->bottom;
    // deque->bottom 에서 문제가 발생할 수도 있으니 segfault생기면 검토 바람
    original_bottom->next = original_top;
    deque->top = original_top->next;
    deque->top->pre = NULL;
    deque->bottom = original_top;
    deque->bottom->pre = original_bottom;
    deque->bottom->next = NULL;
}

// void    ra(t_node **head_a)
// {
//     t_node *temp;

//     temp = *head_a;
//     while (temp->next)
//         temp = temp->next;
//     temp->next = *head_a;
//     *head_a = (*head_a)->next;
// }

// void    rb(t_node **head_b)
// {
//     t_node *temp;

//     temp = *head_b;
//     while (temp->next)
//         temp = temp->next;
//     temp->next = *head_b;
//     *head_b = (*head_b)->next;
// }

// void    rr(t_node **head_a, t_node **head_b)
// {
//     ra(head_a);
//     rb(head_b);
// }