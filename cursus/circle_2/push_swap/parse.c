#include "push_swap.h"

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
