#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# define STANDARD_INPUT 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_n {
	int				fd;
	char			*backup;
	struct s_n		*next;
}	t_n;

void    ft_instructions(char *instruction, t_deque *deque_a, t_deque *deque_b);
void    init(char *argv[], t_deque *deque_a, t_deque *deque_b);
int     validate_sort(t_deque *deque);
void    push_checker(t_deque *to, t_deque *from);
void    compare_max_min_checker(t_deque *to);
void    swap_checker(t_deque *deque);
void    rotate_checker(t_deque *deque);
void    reverse_rotate_checker(t_deque *deque);

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
int		find_node(int fd, t_n **head, t_n **cur, t_n **before);
int		add(t_n **head, t_n **cur, t_n **before);
char	*read_file(t_n **head, t_n **cur, t_n **before);
char	*make_str(t_n **head, t_n **cur, t_n **before);
void	remove_node(t_n **head, t_n **cur, t_n **before);

#endif
