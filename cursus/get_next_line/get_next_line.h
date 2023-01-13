#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_node {
    int     fd;
    char    *backup;
    t_node  *next;
} t_node;

# include <fcntl.h>
# include <stdlib.h>

#endif
