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

void free_count(int **count, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(count[i]);
        i++;
    }
    free(count);
}

void from_a_to_b(t_deque *deque_a, t_deque *deque_b)
{
    int **count;
    int min_idx;

    while (deque_a->size > 0)
    {
        if (deque_b->size < 2)
            push(deque_b, deque_a);
        else
        {
            count = greedy(deque_a, deque_b);
            min_idx = find_min_instructions(count, deque_a->size);
            execute_instructions(count[min_idx], deque_a, deque_b);
            // int i = 0;
            // while (i < deque_a->size)
            // {
            //     ft_printf("RA : %d RB : %d RR : %d RRA : %d RRB : %d RRR : %d total: %d\n", count[i][RA], count[i][RB], count[i][RR], count[i][RRA], count[i][RRB], count[i][RRR],  count[i][TOTAL_IDX]);
            //     i++;
            // }
            // ft_printf("\n");
            free_count(count, (deque_a->size + 1)); // 이 부분에서 count를 free 해줘야 함
        }
    }
}

void from_b_to_a(t_deque *deque_b, t_deque *deque_a)
{
    int **count;
    int min_idx;

    while (deque_b->size > 0)
    {
        if (deque_a->size < 2)
            push(deque_a, deque_b);
        else
        {
            count = greedy(deque_b, deque_a);
            min_idx = find_min_instructions(count, deque_b->size);
            execute_instructions(count[min_idx], deque_a, deque_b);
            // int i = 0;
            // while (i < deque_a->size)
            // {
            //     ft_printf("RA : %d RB : %d RR : %d RRA : %d RRB : %d RRR : %d total: %d\n", count[i][RA], count[i][RB], count[i][RR], count[i][RRA], count[i][RRB], count[i][RRR],  count[i][TOTAL_IDX]);
            //     i++;
            // }
            // ft_printf("\n");
            free_count(count, (deque_b->size + 1)); // 이 부분에서 count를 free 해줘야 함
        }
    }
}

int main(int argc, char *argv[])
{
    t_deque deque_a;
    t_deque deque_b;

    // if (argc < 2)
    //     exit(EXIT_FAILURE);
    // deque_a.top = add_node();
    // deque_a.size = make_linkedlist(argv, 0, &deque_a);
    // if (!deque_a.size)
    // {
    //     write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
    //     exit(EXIT_FAILURE);
    // }
    // deque_b.size = 0;
    // from_a_to_b(&deque_a, &deque_b);

    just_test(argv);

    return (EXIT_SUCCESS);
}
