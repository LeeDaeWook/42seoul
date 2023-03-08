#ifndef CHECKER_H
# define CHECKER_H

#include "get_next_line.h"
#include "push_swap.h"

# define STANDARD_INPUT 0

void    ft_instructions(char *instruction, t_deque *deque_a, t_deque *deque_b);
void    init(char *argv[], t_deque *deque_a, t_deque *deque_b);
int     validate_sort(t_deque *deque);

#endif
