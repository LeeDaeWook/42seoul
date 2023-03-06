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
        r_rr_from(node, from, count, ROTATE);
    else if (idx > (from->size / 2))
        r_rr_from(node, from, count, REVERSE_ROTATE);
    idx = find_location_b(node, to);
    if (idx <= (to->size / 2))
        r_rr_to(idx, to, count, ROTATE);
    else if (idx > (to->size / 2))
        r_rr_to(idx, to, count, REVERSE_ROTATE);
    rr_rrr(count);
    idx = 0;
    while (idx < TOTAL_IDX)
    {
        count[TOTAL_IDX] += count[idx];
        idx++;
    }
}

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
        while (idx < deque->size) // segfault 원인
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

void r_rr_from(t_node *node, t_deque *stack, int *count, int flag)
{
    t_node *temp;

    temp = node;
    while (temp && temp->num != stack->top->num)
    {
        if (flag == ROTATE)
        {
            if (stack->stack == STACK_A)
                count[RA] += 1;
            else if (stack->stack == STACK_B)
                count[RB] += 1;
            temp = temp->pre;
        }
        else if (flag == REVERSE_ROTATE)
        {
            if (stack->stack == STACK_A)
                count[RRA] += 1;
            else if (stack->stack == STACK_B)
                count[RRB] += 1;
            temp = temp->next;
        }
    }
}

void r_rr_to(int idx, t_deque *stack, int *count, int flag)
{
    while ((flag == ROTATE && idx > 0) || (flag == REVERSE_ROTATE && idx < stack->size))
    {
        if (flag == ROTATE)
        {
            if (stack->stack == STACK_A)
                count[RA] += 1;
            else if (stack->stack == STACK_B)
                count[RB] += 1;
            idx--;
        }
        else if (flag == REVERSE_ROTATE)
        {
            if (stack->stack == STACK_A)
                count[RRA] += 1;
            else if (stack->stack == STACK_B)
                count[RRB] += 1;
            idx++;
        }
    }
}

void rr_rrr(int *count)
{
    if (count[RA] >= count[RB])
        count[RR] = count[RB];
    else if (count[RA] < count[RB])
        count[RR] = count[RA];
    count[RA] -= count[RR];
    count[RB] -= count[RR];

    if (count[RRA] >= count[RRB])
        count[RRR] = count[RRB];
    else if (count[RRA] < count[RRB])
        count[RRR] = count[RRA];
    count[RRA] -= count[RRR];
    count[RRB] -= count[RRR];
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

void execute_instructions(int *count, t_deque *from, t_deque *to)
{
    if (count[RA] && from->stack == STACK_A)
        recursion_r_rr(count, from, RA);
    else if (count[RA] && to->stack == STACK_A)
        recursion_r_rr(count, to, RA);
    if (count[RRA] && from->stack == STACK_A)
        recursion_r_rr(count, from, RRA);
    else if (count[RRA] && to->stack == STACK_A)
        recursion_r_rr(count, to, RRA);
    if (count[RB] && from->stack == STACK_B)
        recursion_r_rr(count, from, RB);
    else if (count[RB] && to->stack == STACK_B)
        recursion_r_rr(count, to, RB);
    if (count[RRB] && from->stack == STACK_B)
        recursion_r_rr(count, from, RRB);
    else if (count[RRB] && to->stack == STACK_B)
        recursion_r_rr(count, to, RRB);
    if (count[RR])
        recursion_rr_rrr(count, from, to, RR);
    else if (count[RRR])
        recursion_rr_rrr(count, from, to, RRR);
    push(to, from);
}

void recursion_r_rr(int *count, t_deque *deque, int idx)
{
    if (!count[idx])
        return;
    if (idx == RA || idx == RB)
        rotate(deque);
    else if (idx == RRA || idx == RRB)
        reverse_rotate(deque);
    print_instructions(idx, NULL);
    count[idx] -= 1;
    if (count[idx] > 0)
        recursion_r_rr(count, deque, idx);
}

void recursion_rr_rrr(int *count, t_deque *from, t_deque *to, int idx)
{
    if (idx == RR)
    {
        rotate(from);
        rotate(to);
    }
    else if (idx == RRR)
    {
        reverse_rotate(from);
        reverse_rotate(to);
    }
    print_instructions(idx, NULL);
    count[idx] -= 1;
    if (count[idx] > 0)
        recursion_rr_rrr(count, from, to, idx);
}
