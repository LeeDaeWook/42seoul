#include "checker.h"

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
    if (!to->size)
        to->bottom = to->top;
    (to->size)++;
    (from->size)--;
    if (!(from->size))
        ft_bzero((void*)from, sizeof(t_deque));
    compare_max_min(to);
    print_instructions(PUSH, to);
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


void reverse_rotate(t_deque *deque)
{
    t_node *original_top;
    t_node *original_bottom;

    original_top = deque->top;
    original_bottom = deque->bottom;
    original_top->pre = original_bottom;
    original_bottom->next = original_top;
    deque->bottom = original_bottom->pre;
    deque->bottom->next = NULL;
    deque->top = original_bottom;
    deque->top->pre = NULL;
}

void rotate(t_deque *deque)
{
    t_node *original_top;
    t_node *original_bottom;

    original_top = deque->top;
    original_bottom = deque->bottom;
    original_bottom->next = original_top;
    deque->top = original_top->next;
    deque->top->pre = NULL;
    deque->bottom = original_top;
    deque->bottom->pre = original_bottom;
    deque->bottom->next = NULL;
}

void    swap(t_deque *deque)
{
    t_node  *second_node;

    if (deque->size < 2)
    {
        ft_printf("at least 2 arguments needed\n");
        exit(EXIT_FAILURE);
    }
    second_node = deque->top->next;
    deque->top->next = second_node->next;
    second_node->next->pre = deque->top; // problem!!!!!!!!!!!!!!!!!
    second_node->next = deque->top;
    deque->top->pre = second_node;
    deque->top = second_node;
    deque->top->pre = NULL;
    print_instructions(SWAP, deque);
}

long long ft_atoi_ll(const char *s)
{
	long long		result;
	int		sign;
	char	*str;

	str = (char *)s;
	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= sign;
	return (result);
}

void is_integer(char *argv)
{
    int i;

    i = 0;
    while (argv[i]) // step1. 인자가 숫자인지 확인
    {
        if (!ft_isdigit(argv[i]) && argv[i] != '-') // 숫자가 아니면
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

void make_linkedlist(char *argv[], t_deque *deque, int flag, t_node *temp)
{
    char **arguments;

    argv++;
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
            (deque->size)++;
        }
        argv++;
    }
    if (!flag)
        exit(EXIT_FAILURE);
    deque->bottom = temp;
}

void print_instructions(int flag, t_deque *stack)
{
    if (stack && flag == SWAP && stack->stack == STACK_A)
        ft_printf("sa\n");
    else if (stack && flag == SWAP && stack->stack == STACK_B)
        ft_printf("sb\n");
    else if (stack && flag == PUSH && stack->stack == STACK_A)
        ft_printf("pa\n");
    else if (stack && flag == PUSH && stack->stack == STACK_B)
        ft_printf("pb\n");
    else if (!stack && flag == RA)
        ft_printf("ra\n");
    else if (!stack && flag == RB)
        ft_printf("rb\n");
    else if (!stack && flag == RRA)
        ft_printf("rra\n");
    else if (!stack && flag == RRB)
        ft_printf("rrb\n");
    else if (!stack && flag == RR)
        ft_printf("rr\n");
    else if (!stack && flag == RRR)
        ft_printf("rrr\n");
}

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

void ft_instructions(char *instruction, t_deque *deque_a, t_deque *deque_b)
{
    if (!ft_strcmp(instruction, "ra\n"))
        rotate(deque_a);
    else if (!ft_strcmp(instruction, "rb\n"))
        rotate(deque_b);
    else if (!ft_strcmp(instruction, "rra\n"))
        reverse_rotate(deque_a);
    else if (!ft_strcmp(instruction, "rrb\n"))
        reverse_rotate(deque_b);
    else if (!ft_strcmp(instruction, "pa\n"))
    {
        ft_printf("stack a:  %d %d %d\n", deque_a->top->num, deque_a->top->next->num, deque_a->bottom->num);
        push(deque_a, deque_b);
        ft_printf("stack a: %d %d %d \n", deque_a->top->num, deque_a->top->next->num, deque_a->bottom->num);
    }
    else if (!ft_strcmp(instruction, "pb\n"))
    {
        ft_printf("stack b:  %p\n", deque_b->top);
        push(deque_b, deque_a);
        ft_printf("stack b:  %d\n", deque_b->top->num);
    }
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
        // ft_printf("stack a: %d\n", temp->num);
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