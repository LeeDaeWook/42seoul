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
    if (to->size == 0)
        to->bottom = to->top;
    (to->size)++;
    (from->size)--;
    if (!(from->size))
    {
        from->top = NULL;
        from->bottom = NULL;
        from->max = NULL;
        from->min = NULL;
    }
    compare_max_min(to);
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

// void push(t_deque *to, t_deque *from, int *to_size, int *from_size)
// {
//     t_node *temp;

//     if (*from_size == 0)
//         return;
//     if (*from_size == 1)
//     {
//         from->top->next = to->top;
//         from->top->pre = to->bottom;
//         to->top = from->top;
//         from->top = NULL;
//         from->bottom = NULL;
//     }
//     else
//     {
//         temp = from->top->next;
//         from->top->next = to->top;
//         from->top->pre = to->bottom;
//         to->top = from->top;
//         from->top = temp;
//         if (from->top != from->bottom)
//             from->top->pre = from->bottom;
//         else
//         {
//             from->top->pre = NULL;
//             from->top->next = NULL;
//         }
//     }
//     if (*to_size == 0)
//         to->bottom = to->top;
//     (*to_size)++;
//     (*from_size)--;
//     if (!to->max && !to->min)
//     {
//         to->max = to->top;
//         to->min = to->top;
//     }
//     else if (to->max && to->top->num > to->max->num)
//         to->max = to->top;
//     else if (to->min && to->top->num < to->min->num)
//         to->min = to->top;
// }

// void pa(t_node **head_a, t_node **head_b, int *stack_size_a, int *stack_size_b)
// {
//     t_node *temp;

//     if (stack_size_b == 0)
//         return;
//     temp = (*head_b)->next;
//     (*head_b)->next = *head_a;
//     *head_a = *head_b;
//     *head_b = temp;
//     (*stack_size_a)++;
//     (*stack_size_b)--;
// }

// void pb(t_node **head_a, t_node **head_b, int *stack_size_a, int *stack_size_b)
// {
//     t_node *temp;

//     if (stack_size_a == 0)
//         return;
//     temp = (*head_a)->next;
//     (*head_a)->next = *head_b;
//     *head_b = *head_a;
//     *head_a = temp;
//     (*stack_size_b)++;
//     (*stack_size_a)--;
// }