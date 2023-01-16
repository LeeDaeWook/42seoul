#include "get_next_line.h"

//#include <stdio.h>

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
        return (remove_node(&lst));
    line = read_file(&lst, buf);
    return (line);
}

char* remove_node(t_list *lst)
{
    t_node  *temp;

    temp = lst->cur;
    lst->before->next = lst->cur->next;
    lst->cur = lst->cur->next;
    free(temp);
    temp = 0; // dangling pointer 처리
    return (0);
}

int	find_node(int fd, t_list *lst)
{
	t_node	*temp;

	temp = lst->head;
	while (temp)
	{
		if (fd == temp->fd)
		{
			lst->cur = temp;
			return (1);
		}
		lst->before = temp; // cur 이전의 노드를 before에 추가
		temp = temp->next;
	}
	return (0);
}

int	add_node(int fd, t_list *lst)
{
	t_node	*new;
	t_node	*temp;

	new = (t_node*)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->fd = fd;
	if (lst->head)
	{
		temp = lst->head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		lst->head = new;
	//lst->before = 0; // static으로 선언하면 bss영역에서 자동으로 최초에 0으로 초기화하기 때문에 필요없을듯(?)
	lst->cur = new;
	return (1);
}

char	*read_file(t_list *lst, char *buf)
{
	char    *line;
    int     read_size;
    char    *temp;

	line = 0;
	if (lst->cur->backup)
		line = ft_strdup(lst->cur->backup);
    while ((read_size = read(lst->cur->fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_size] = '\0';
        if (!line)
			line = ft_strdup(buf);
        else
			line = ft_strjoin(line, buf);
        if ((temp = ft_strchr(line, '\n')) != 0)
        {
            *(temp + 1) = '\0';
            lst->cur->backup = ft_strdup(ft_strchr(buf, '\n') + 1); // buf에서 개행 이후 읽어온 부분 저장
			break;
        }
    }
    return (line);
}