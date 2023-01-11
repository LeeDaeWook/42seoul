#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char        *buf;
    char        *line;
    int         read_size;
    static int  backup; // 읽고있던 fd의 위치를 담고 있어야함   

    buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (fd == -1)
        return (0);
    while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_size] = '\0';
        if (!line)
            line = ft_strdup(buf);
        else
            line = 
        if ((backup = ft_strchr(buf, '\n')) != 0)
            line = 
            
    }
}