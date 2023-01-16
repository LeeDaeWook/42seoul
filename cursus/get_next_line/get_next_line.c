/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:38:08 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/16 10:45:18 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	lst;
	char			*line;
	char			*buf;

	if (fd < 0)
		return (0);
	if (!find_node(fd, &lst))
	{
		if (!add_node(fd, &lst))
			return (0);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (remove_node(&lst));
	line = read_file(&lst, buf);
	free(buf); // 필요??
	return (line);
}

int	find_node(int fd, t_list *lst)
{
	t_node1	*temp;

	temp = lst->head;
	while (temp)
	{
		if (fd == temp->fd)
		{
			lst->cur = temp;
			return (1);
		}
		lst->before = temp;
		temp = temp->next;
	}
	return (0);
}

int	add_node(int fd, t_list *lst)
{
	t_node1	*new;
	t_node1	*temp;

	new = (t_node1 *)malloc(sizeof(t_node1));
	if (!new)
		return (0);
	new->fd = fd;
	if (lst->head)
	{
		temp = lst->head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		lst->before = temp;
	}
	else
		lst->head = new;
	lst->cur = new;
	lst->cur->next = 0;
	return (1);
}

char	*read_file(t_list *lst, char *buf)
{
	char	*line;
	int		read_size;
	char	*temp;

	line = 0;
 	if (lst->cur->backup)
 		line = ft_strdup(lst->cur->backup);
 	while (1)
 	{
 		read_size = read(lst->cur->fd, buf, BUFFER_SIZE);
 		if (read_size == 0 && line) // 다 읽고 출력도 다했을때, 다 읽고 출력은 아직 다 못했을때
 			break ;
		//else if (read_size == 0 && !line)
			//break;
 		else if (read_size == -1)
 			return (0);
 		buf[read_size] = '\0';
 		if (!line)
 			line = ft_strdup(buf);
 		else
 			line = ft_strjoin(line, buf);
		if (!line)
			return (0);
 		if (line && (temp = ft_strchr(line, '\n')) != 0)
			return (make_str(lst, line, buf, temp));
			//make_str(lst, buf, temp);
 	}
 	remove_node(lst);
 	return (line);
}

char	*make_str(t_list *lst, char *line, char *buf, char *temp)
{
	*(temp + 1) = '\0';
	if (lst->cur->backup)
		free(lst->cur->backup);
	lst->cur->backup = ft_strdup(ft_strchr(buf, '\n') + 1);
	return (line);
}

char* remove_node(t_list*lst)
{
	if (lst->cur)
	{
		if (lst->cur->backup)
			free(lst->cur->backup);
	}
	if (lst->before)
		lst->before->next = lst->cur->next;
	free(lst->cur);
	lst->cur = 0;
	return (0);
}