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

// void    rra(t_node **head_a)
// {
//     t_node *temp;

//     temp = *head_a;
//     while (temp->next->next) // 마지막에서 두 번째 노드 찾기
//         temp = temp->next;
//     temp->next->next = (*head_a);
//     *head_a = temp->next;
//     temp->next = NULL;
// }

// void    rrb(t_node **head_b)
// {
//     t_node *temp;

//     temp = *head_b;
//     while (temp->next->next) // 마지막에서 두 번째 노드 찾기
//         temp = temp->next;
//     temp->next->next = (*head_b);
//     *head_b = temp->next;
//     temp->next = NULL;
// }

// void    rrr(t_node **head_a, t_node **head_b)
// {
//     rra(head_a);
//     rrb(head_b);
// }