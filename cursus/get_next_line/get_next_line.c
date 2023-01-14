#include "get_next_line.h"

#include <stdio.h>

char    *get_next_line(int fd)
{
    static t_list   lst;
    char            *line;
    char	        *buf;
    
    if (fd == -1)
        return (0);
    if (!find_node(fd, &lst)) // input으로 들어온 fd를 가지고 있는 node가 현재 연결리스트에 없으면 0 반환
    {
        if (!add_node(fd, &lst))
            return (0);
    }
    buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
		return (0);
        //return (remove_node(lst));
        
    line = read_file(&lst, buf);
    return (line);
}

/*
int remove_node(t_list *lst)
{
    t_node  *temp;

    temp = lst->cur;
    lst->cur = lst->cur->next;
    free(temp);

    return (0);
}
*/