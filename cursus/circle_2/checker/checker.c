#include "checker.h"

void ft_instructions(char *instruction, t_deque *deque_a, t_deque *deque_b)
{
    if (!ft_strcmp(instruction, "ra\n"))
        rotate(deque_a, RA);
    else if (!ft_strcmp(instruction, "rb\n"))
        rotate(deque_b, RB);
    else if (!ft_strcmp(instruction, "rra\n"))
        reverse_rotate(deque_a, RRA);
    else if (!ft_strcmp(instruction, "rrb\n"))
        reverse_rotate(deque_b, RRB);
    else if (!ft_strcmp(instruction, "pa\n"))
        push(deque_a, deque_b);
    else if (!ft_strcmp(instruction, "pb\n"))
        push(deque_b, deque_a);
    else if (!ft_strcmp(instruction, "sa\n"))
        swap(deque_a);
    else if (!ft_strcmp(instruction, "sb\n"))
        swap(deque_b);
}

void init(char *argv[], t_deque *deque_a, t_deque *deque_b)
{
    ft_bzero((void *)deque_a, sizeof(t_deque));
    deque_a->top = add_node();
    make_linkedlist(argv, deque_a, 0, deque_a->top);
    deque_a->stack = STACK_A;
    if (!deque_a->size)
    {
        write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
        exit(EXIT_FAILURE);
    }
    ft_bzero((void *)deque_b, sizeof(t_deque));
    deque_b->stack = STACK_B;
}

int validate_sort(t_deque *deque)
{
    t_node *temp;

    temp = deque->top;
    while (temp->next)
    {
        if (temp->num > temp->next->num)
            return (0);
        temp = temp->next;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    t_deque deque_a;
    t_deque deque_b;
    char    *instruction;

    init(argv, &deque_a, &deque_b);
    while (1)
    {
        instruction = get_next_line(STANDARD_INPUT);
        if (!instruction)
            break;
        ft_instructions(instruction, &deque_a, &deque_b);
    }
    if (validate_sort(&deque_a))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    return (EXIT_SUCCESS);
}