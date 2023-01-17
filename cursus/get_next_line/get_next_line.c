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

#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	lst;
	char			*line;

	if (fd < 0)
		return (0);
	if (!find_node(fd, &lst))
	{
		if (!add_node(fd, &lst))
			return (0);
	}
	line = read_file(&lst);
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
	new->backup = 0;
	//new->backup = ft_strdup("");

	// if (!new->backup)
	// {
	// 	free(new);
	// 	return (0);
	// }
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

char	*read_file(t_list *lst)
{
	char	*line;
	int		read_size;
	char	buf[BUFFER_SIZE + 1];

	line = 0;
	if (lst->cur->backup)
 		line = ft_strdup(lst->cur->backup);
	while (1)
 	{
		read_size = read(lst->cur->fd, buf, BUFFER_SIZE);
		if (read_size == -1 || (read_size == 0 && !line))
			break;
 		buf[read_size] = '\0';
 		if (!line)
 			line = ft_strdup(buf);
 		else
 			line = ft_strjoin(line, buf);
		if (!line)
			return (0);
		if (ft_strchr(buf, '\n'))
			return (make_str(lst, line, buf));
 	}
	remove_node(lst);
 	return (line);

	// while(!ft_strchr(lst->cur->backup, '\n'))
	// {
	// 	read_size = read(lst->cur->fd, buf, BUFFER_SIZE);
	// 	if (read_size == -1 || read_size == 0)
	// 		break;
 	// 	buf[read_size] = '\0';
 	// 	lst->cur->backup = ft_strjoin(lst->cur->backup, buf);
	// 	if (!lst->cur->backup)
	// 	{
	// 		remove_node(lst);
	// 		return (0);
	// 	}
	// }
	// return (make_str(lst));
}

char	*make_str(t_list *lst, char *line, char *buf)
//char	*make_str(t_list *lst)
{
	char	*temp;

	temp = ft_strchr(line, '\n');
	if ((temp - line + 1) < ft_strlen(line))
		*(temp + 1) = '\0';
	else
		line = ft_strjoin(line, "\0");
	if (lst->cur->backup)
	{
		free(lst->cur->backup);
		lst->cur->backup = 0;
	}
	if (ft_strlen(buf) > ft_strchr(buf, '\n') - buf + 1)
		lst->cur->backup = ft_strdup(ft_strchr(buf, '\n') + 1);
	return (line);

	// char	*temp;
	// char	*line;

	// temp = lst->cur->backup;
	// line = ft_strdup(lst->cur->backup);
	// lst->cur->backup = ft_strdup(ft_strchr(lst->cur->backup, '\n') + 1);
	// free(temp);
	
	// temp = ft_strchr(line, '\n');	
	// if ((temp - line + 1) < ft_strlen(line))
	// 	*(temp + 1) = '\0';
	// else
	// 	line = ft_strjoin(line, "\0");
	// if (!line)
	// {
	// 	free(line);
	// 	//lst->cur->backup = 0;
	// }
	// return (line);

	/*

	line = ft_substr '\n' 까지
	lst->cur->backup = ft_substr '\n' 이후부터 '\0'까지

	*/
}

char* remove_node(t_list*lst)
{
	t_node1	*temp;

	temp = lst->cur;
	free(lst->cur->backup);
	lst->cur->backup = 0;
	if (lst->head == lst->cur)
	{
		lst->cur = lst->cur->next;
		lst->head = 0;
	}
	else
		lst->before->next = lst->cur->next;
	free(temp);
	temp = 0;
	return (0);
}












/*
char	*read_file(t_list *lst, char *buf)
{
	char	*line;
	int		read_size;
	char	*temp;

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
		if (!line)
			return (0);
 		if ((temp = ft_strchr(line, '\n')) != 0)
			return (make_str(lst, line, buf, temp));
 	}
	if (read_size == -1)
		return (0);
	remove_node(lst);
 	return (line);
}

char	*make_str(t_list *lst, char *line, char *buf, char* temp)
{
	if ((temp - line + 1) < ft_strlen(line))
		*(temp + 1) = '\0';
	else
		line = ft_strjoin(line, "\0");
	if (lst->cur->backup)
	{
		free(lst->cur->backup);
		lst->cur->backup = 0;
	}
	if (ft_strlen(buf) > ft_strchr(buf, '\n') - buf + 1)
		lst->cur->backup = ft_strdup(ft_strchr(buf, '\n') + 1);
	free(buf);
	buf = 0;
	return (line);
}

*/