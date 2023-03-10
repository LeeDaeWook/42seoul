#ifndef CHECKER_H
# define CHECKER_H

// # include "./get_next_line/get_next_line.h"
# include "push_swap.h"

# define STANDARD_INPUT 0

void    ft_instructions(char *instruction, t_deque *deque_a, t_deque *deque_b);
void    init(char *argv[], t_deque *deque_a, t_deque *deque_b);
int     validate_sort(t_deque *deque);
void    push_checker(t_deque *to, t_deque *from);
void    compare_max_min_checker(t_deque *to);
void    swap_checker(t_deque *deque);
void    rotate_checker(t_deque *deque);
void    reverse_rotate_checker(t_deque *deque);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// # include <unistd.h>
// # include <stdlib.h>

typedef struct s_n {
	int				fd;
	char			*backup;
	struct s_n	*next;
}	t_n;

char			*get_next_line(int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *src);
unsigned int	ft_strlen_gnl(const char *str);
char			*ft_strjoin_gnl(char *s1, char *s2);
int				find_node(int fd, t_n **head, t_n **cur, t_n **before);
int				adding(t_n **head, t_n **cur, t_n **before);
char			*read_file(t_n **head, t_n **cur, t_n **before);
char			*make_str(t_n **head, t_n **cur, t_n **before);
void			remove_node(t_n **head, t_n **cur, t_n **before);

#endif
