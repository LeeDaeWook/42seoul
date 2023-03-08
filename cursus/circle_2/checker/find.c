#include "push_swap.h"

int find_location_b(t_node *node, t_deque *deque)
{
    int idx;
    t_node *temp;

    idx = 1;
    temp = deque->top;
    if (node->num > deque->max->num || node->num < deque->min->num)
        idx = find_idx(deque->max, deque);
    else if (deque->stack == STACK_B)
    {
        while (idx < deque->size)
        {
            if (node->num < temp->num && node->num > temp->next->num)
                break;
            idx++;
            temp = temp->next;
        }
    }
    return (idx);
}

int find_location_a(t_node *node, t_deque *deque)
{
    int idx;
    t_node *temp;

    idx = 1;
    temp = deque->top;
    if (node->num < deque->min->num)
        idx = find_idx(deque->min, deque);
    else if (node->num > deque->max->num)
        idx = find_idx(deque->max, deque) + 1;
    else
    {
        while (idx < deque->size)
        {
            if (node->num > temp->num && node->num < temp->next->num)
                return (idx);
            idx++;
            temp = temp->next;
        }
        idx = 0;
    }
    return (idx);
}

int find_idx(t_node *node, t_deque *stack)
{
    t_node *temp;
    int idx;

    temp = stack->top;
    idx = 0;
    while (node->num != temp->num)
    {
        idx++;
        temp = temp->next;
    }
    return (idx);
}

int find_min_instructions(int **count, int size)
{
    int i;
    int min;
    int min_idx;

    i = 0;
    min = INTEGER_MAX;
    while (i < size)
    {
        if (count[i][TOTAL_IDX] < min)
        {
            min = count[i][TOTAL_IDX];
            min_idx = i;
        }
        i++;
    }
    return (min_idx);
}

t_node *find_min_node(t_deque *stack)
{
    t_node *temp;
    t_node *node;
    int min_num;

    temp = stack->top;
    min_num = INTEGER_MAX;
    while (temp)
    {
        if (temp->num < min_num)
        {
            min_num = temp->num;
            node = temp;
        }
        temp = temp->next;
    }
    return (node);
}