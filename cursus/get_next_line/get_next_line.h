#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_node {
    int     fd;
    char    *backup;
    struct s_node  *next;
}   t_node;

typedef struct s_list {
    t_node  *head;
    t_node  *cur;
    //t_node  *before;  
    //t_node  *tail;
}   t_list;

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
unsigned int	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int	    find_node(int fd, t_list *lst);
int	    add_node(int fd, t_list *lst);
char	*read_file(t_list *lst, char* buf);

#endif