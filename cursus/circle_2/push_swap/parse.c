#include "push_swap.h"

void is_integer(char *argv)
{
    int i;

    i = 0;
    while (argv[i]) // step1. 인자가 숫자인지 확인
    {
        if (!ft_isdigit(argv[i])) // 숫자가 아니면
        {
            write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if (ft_atoi_ll(argv) > INTEGER_MAX || ft_atoi_ll(argv) < INTEGER_MIN) // step2. 인자가 int 범위내에 있는지 확인
    {
        write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
        exit(EXIT_FAILURE);
    }
}

void validate_overlap_sorting(t_deque *deque, int num, int *flag)
{
    t_node *temp;

    temp = deque->top;
    while (temp->next)
    {
        if (temp->num == num)
        {
            write(STANDARD_ERROR, "Error\n", ft_strlen("Error\n"));
            exit(EXIT_FAILURE);
        }
        if (temp->num > num)
            *flag = 1;
        temp = temp->next;
    }
}

int make_linkedlist(char *argv[], int stack_size, t_deque *deque)
{
    t_node  *temp;
    char    **arguments;
    int     flag;

    temp = deque->top;
    argv++;
    flag = 0;
    while (*argv)
    {
        arguments = ft_split(*argv, ' ');
        while (*arguments)
        {
            is_integer(*arguments);
            temp->num = ft_atoi(*arguments);
            validate_overlap_sorting(deque, temp->num, &flag);
            if (*(arguments + 1) || *(argv + 1))
            {
                temp->next = add_node();
                temp->next->pre = temp;
                temp = temp->next;
            }
            arguments++;
            stack_size++;
        }
        argv++;
    }
    if (flag == 0)
        exit(EXIT_FAILURE);
    deque->bottom = temp;
    return (stack_size);
}