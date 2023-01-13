#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char            *buf;
    char            *line;
    int             read_size;
    static t_node   node;;   

    node.fd = fd;
    buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (0);
    if (fd == -1)
        return (0);
    while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_size] = '\0';
        if (!line)
            line = ft_strdup(buf);
        else
            line = ft_strcat(line, buf);
        if ((buf = ft_strchr(buf, '\n')) != 0)
            node.backup = ft_strdup(buf + 1); // buf에서 개행이후 읽어온 부분 저장
    }
    return (line);
}