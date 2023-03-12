#include "push_swap.h"

void is_integer(char *argv)
{
    int i;

    i = 0;
    while (argv[i])
    {
        if (!ft_isdigit(argv[i]) && argv[i] != '-')
            print_error();
        i++;
    }
    if (ft_atoi_ll(argv) > INTEGER_MAX || ft_atoi_ll(argv) < INTEGER_MIN)
        print_error();
}

void validate_overlap_sorting(t_deque *stack, int num, int *flag)
{
    t_node *temp;

    temp = stack->top;
    while (temp->next)
    {
        if (temp->num == num)
            print_error();
        if (temp->num > num)
            *flag = 1;
        temp = temp->next;
    }
}

t_node *add_node(void)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        print_error();
    new_node->pre = NULL;
    new_node->next = NULL;
    return (new_node);
}

t_node *create_node(t_node *temp)
{
    temp->next = add_node();
    temp->next->pre = temp;
    temp = temp->next;
    return (temp);
}

void make_linkedlist(char *argv[], t_deque *stack, int flag, t_node *temp)
{
    char **arguments;
    char **arguments_temp;

    while (*argv)
    {
        arguments = ft_split(*argv, ' ');
        if (!*arguments)
            print_error();
        arguments_temp = arguments;
        while (*arguments)
        {
            is_integer(*arguments);
            temp->num = ft_atoi(*arguments);
            validate_overlap_sorting(stack, temp->num, &flag);
            if (*(arguments + 1) || *(argv + 1))
                temp = create_node(temp);
            arguments++;
            (stack->size)++;
        }
        double_free(arguments_temp);
        argv++;
    }
    if (!flag)
        exit(EXIT_FAILURE);
    stack->bottom = temp;
}
