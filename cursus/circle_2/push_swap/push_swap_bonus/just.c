#include "push_swap.h"

void just_print(t_deque *deque, int stack_size)
{
    int i;
    t_node *temp;

    i = 0;
    temp = deque->top;
    ft_printf("---------------위에서 아래로--------------\n");
    while (i < stack_size)
    {
        ft_printf("%d\n", temp->num);
        if (temp->next)
            temp = temp->next;
        i++;
    }
    // ft_printf("\n");

    // ft_printf("---------------아래에서 위로--------------\n");
    // i = stack_size - 1;
    // temp = deque->bottom;
    // while (i >= 0)
    // {
    //     ft_printf("%d\n", temp->num);
    //     temp = temp->pre;
    //     i--;
    // }
}

// void just_test(char *argv[])
// {
//     t_deque deque_a;
//     t_deque deque_b;

//     deque_a.top = add_node();
//     deque_a.size = make_linkedlist(argv, 0, &deque_a);
//     deque_a.stack = STACK_A;
//     // deque_a.max = NULL;
//     // deque_a.min = NULL;

//     deque_b.size = 0;
//     deque_b.max = NULL;
//     deque_b.min = NULL;
//     deque_b.top = NULL;
//     deque_b.bottom = NULL;
//     deque_b.stack = STACK_B;

//     // ft_printf("\n--------------첫 번째 푸시스왑----------\n");
//     push_swap1(&deque_a, &deque_b);
//     // deque_a.top = NULL;
//     // deque_a.bottom = NULL;
//     // deque_a.max = NULL;
//     // deque_a.min = NULL;
//     // ft_printf("\n--------------두 번째 푸시스왑----------\n");
//     push_swap2(&deque_b, &deque_a);
//     final_sort(&deque_a, deque_a.min);

//     ft_printf("---------------stack A--------------\n");
//     just_print(&deque_a, deque_a.size);
//     // ft_printf("---------------stack B--------------\n");
//     // just_print(&deque_b, deque_b.size);

//     // ft_printf("last    :%d %d %d\n", deque_a.top->num, deque_a.top->next->num, deque_a.top->next->next->num);


//     // rotate(&deque_a);
//     // reverse_rotate(&deque_a);
//     // swap(&deque_a, deque_a.size);
//     // push(&deque_a, &deque_b, &(deque_a.size), &(deque_b.size));
//     // push(&deque_a, &deque_b, &(deque_a.size), &(deque_b.size));
//     // push(&deque_a, &deque_b, &(deque_a.size), &(deque_b.size));
//     // push(&deque_b, &deque_a, &(deque_b.size), &(deque_a.size));
//     // push(&deque_b, &deque_a, &(deque_b.size), &(deque_a.size));
//     // push(&deque_b, &deque_a, &(deque_b.size), &(deque_a.size));
// }
