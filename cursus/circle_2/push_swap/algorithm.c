#include "push_swap.h"

int **greedy(t_deque *from, t_deque *to)
{
    t_node *temp;
    int **count;
    int i;

    temp = from->top;
    count = (int **)malloc(sizeof(int *) * from->size);
    i = 0;
    while (temp)
    {
        count[i] = (int *)malloc(sizeof(int) * 7);
        fill_count(temp, from, to, count[i]);
        temp = temp->next;
        i++;
    }
    return (count);
}

void fill_count(t_node *node, t_deque *from, t_deque *to, int *count)
{
    int idx;
    int total;

    ft_bzero((void *)count, sizeof(int) * 7);
    idx = find_idx(node, from);
    if (idx <= (from->size / 2))
        ra_rra(node, from, count, RA);
    else if (idx > (from->size / 2))
        ra_rra(node, from, count, RRA);

    idx = find_location(node, to);
    if (idx <= (to->size / 2))
        rb_rrb(idx, count, RB);
    else if (idx > (to->size / 2))
        rb_rrb(idx, count, RRB);
    idx = 0;
    while (idx < TOTAL_IDX)
    {
        count[TOTAL_IDX] += count[idx];
        idx++;
    }
}

int find_location(t_node *node, t_deque *deque)
{
    int idx;
    t_node *temp;

    idx = 1;
    temp = deque->top;
    if (node->num > deque->max->num || node->num < deque->min->num)
        idx = find_idx(deque->max, deque);
    else
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

void ra_rra(t_node *node, t_deque *stack, int *count, int flag)
{
    t_node *temp;

    temp = node;
    while (temp && temp->num != stack->top->num)
    {
        if (flag == RA)
        {
            count[RA] += 1;
            temp = temp->pre;
        }
        else if (flag == RRA)
        {
            count[RRA] += 1;
            temp = temp->next;
        }
    }
}

void rb_rrb(int idx, int *count, int flag)
{
    while (idx > 0)
    {
        if (flag == RB)
            count[RB] += 1;
        else if (flag == RRB)
            count[RRB] += 1;
        idx--;
    }
}

void rr_rrr(t_node *node, t_deque *stack, int *count, int flag)
{
    t_node *temp;

    temp = node;
    while (temp && temp->num != stack->top->num)
    {
        if (flag == STACK_A)
            count[RRA] += 1;
        if (flag == STACK_B)
            count[RRB] += 1;
        temp = temp->next;
    }
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

void execute_instructions(int *count, t_deque *deque_a, t_deque *deque_b)
{
    if (count[RA])
        recursion_r_rr(count, deque_a, RA);
    else if (count[RRA])
        recursion_r_rr(count, deque_a, RRA);
    if (count[RB])
        recursion_r_rr(count, deque_b, RB);
    else if (count[RRB])
        recursion_r_rr(count, deque_b, RRB);
    // if (count[RR])
    // {
    //     recursion_r_rr(count, deque_a, RR);
    //     recursion_r_rr(count, deque_b, RR);
    // }
    push(deque_b, deque_a);
}

void recursion_r_rr(int *count, t_deque *deque, int idx)
{
    if (idx == RA || idx == RB)
        rotate(deque);
    else if (idx == RRA || idx == RRB)
        reverse_rotate(deque);
    count[idx] -= 1;
    if (count[idx] > 0)
        recursion_r_rr(count, deque, idx);
}

// void r(t_node *node, t_deque *stack, int *count, int flag)
// {
//     t_node *temp;

//     temp = node;
//     while (temp && temp->num != stack->top->num)
//     {
//         if (flag == STACK_A)
//             count[RA] += 1;
//         else if (flag == STACK_B)
//             count[RB] += 1;
//         temp = temp->pre;
//     }
// }

// void rr(t_node *node, t_deque *stack, int *count, int flag)
// {
//     t_node *temp;

//     temp = node;
//     while (temp && temp->num != stack->top->num)
//     {
//         if (flag == STACK_A)
//             count[RRA] += 1;
//         if (flag == STACK_B)
//             count[RRB] += 1;
//         temp = temp->next;
//     }
// }