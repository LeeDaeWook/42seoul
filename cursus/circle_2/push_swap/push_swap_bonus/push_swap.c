#include "push_swap.h"

t_node *add_node(void)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
    {
        write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
        exit(EXIT_FAILURE);
    }
    new_node->pre = NULL;
    new_node->next = NULL;
    return (new_node);
}

void push_swap_first(t_deque *from, t_deque *to)
{
    int **count;
    int min_idx;

    while (from->size > 0)
    {
        if (to->size < 2)
            push(to, from);
        else if (to->stack == STACK_B)
        {
            count = greedy(from, to);
            min_idx = find_min_instructions(count, from->size);
            execute_instructions(count[min_idx], from, to);
            free_count(count, (from->size + 1)); // 이 부분에서 count를 free 해줘야 함
        }
        if (from->stack == STACK_A && from->size == 3)
        {
            last_three(from);
            from->max = from->bottom;
            return;
        }
    }
}

void last_three(t_deque *stack)
{
    t_node *temp;

    temp = find_min_node(stack);
    stack->min = temp;
    final_sort(stack, temp);
    temp = stack->top;
    while (temp->next)
    {
        if (temp->num > temp->next->num)
        {
            swap(stack);
            last_three(stack);
            return;
        }
        temp = temp->next;
    }
}

void final_sort(t_deque *stack, t_node *node)
{
    int idx;

    idx = find_idx(node, stack);
    while (node->num != stack->top->num)
    {
        if (idx <= (stack->size / 2))
            rotate(stack);
        else if (idx > (stack->size / 2))
            reverse_rotate(stack);
    }
}

// int main(int argc, char *argv[])
// {
//     t_deque deque_a;
//     t_deque deque_b;

//     if (argc < 2)
//         exit(EXIT_FAILURE);
//     ft_bzero((void*)&deque_a, sizeof(t_deque));
//     deque_a.top = add_node();
//     make_linkedlist(argv, &deque_a, 0, deque_a.top);
//     deque_a.stack = STACK_A;
//     if (!deque_a.size)
//     {
//         write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
//         exit(EXIT_FAILURE);
//     }
//     ft_bzero((void*)&deque_b, sizeof(t_deque));
//     deque_b.stack = STACK_B;
//     push_swap_first(&deque_a, &deque_b);
//     push_swap_second(&deque_b, &deque_a);
//     final_sort(&deque_a, deque_a.min);
//     just_print(&deque_a, deque_a.size);
//     return (EXIT_SUCCESS);
// }
