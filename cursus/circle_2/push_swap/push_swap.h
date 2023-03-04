#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

#define STANDARD_ERROR 2
#define INTEGER_MAX 2147483647
#define INTEGER_MIN -2147483648

#define RA 0
#define RB 1
#define RR 2
#define RRA 3
#define RRB 4
#define RRR 5

#define TOTAL_IDX 6

#define STACK_A 0
#define STACK_B 1

typedef struct s_node
{
    int num;
    struct s_node *pre;
    struct s_node *next;
} t_node;

typedef struct s_deque
{
    struct s_node *top;
    struct s_node *bottom;
    struct s_node *max;
    struct s_node *min;
    int size;
} t_deque;

t_node  *add_node(void);
void    from_a_to_b(t_deque *deque_a, t_deque *deque_b);
void    is_integer(char *argv);
void    validate_overlap_sorting(t_deque *deque, int num, int *flag);
int     make_linkedlist(char *argv[], int stack_size, t_deque *deque);

int     **greedy(t_deque *from, t_deque *to);
void    fill_count(t_node *node, t_deque *from, t_deque *to, int *count);
int     find_location(t_node *node, t_deque *deque);
int     find_idx(t_node *node, t_deque *stack);
void    ra_rra(t_node *node, t_deque *stack, int *count, int flag);
void    rb_rrb(int idx, int *count, int flag);
void    rr_rrr(t_node *node, t_deque *stack, int *count, int flag);
int     find_min_instructions(int **count, int size);
void    execute_instructions(int *count, t_deque *deque_a, t_deque *deque_b);
void    recursion_r_rr(int *count, t_deque *deque, int idx);

void    just_print(t_deque *deque, int stack_size);
void    just_test(char *argv[]);

long long   ft_atoi_ll(const char *s);

void    swap(t_deque *deque, int stack_size);
void    push(t_deque *to, t_deque *from);
void    compare_max_min(t_deque *to);
void    rotate(t_deque *deque);
void    reverse_rotate(t_deque *deque);

#endif