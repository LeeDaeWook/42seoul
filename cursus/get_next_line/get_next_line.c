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

	// if (!line && lst.cur->backup) // 이 부분에 뭔가 문제의 키포인트가 있음
	// {
	// 	line = ft_strdup(lst.cur->backup);
	// 	remove_node(&lst);
	// 	return (line);
	// }
		
	if (line && ft_strchr(line, '\n'))
		line = make_str(&lst);
	else
		remove_node(&lst);
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
	new->backup = ft_strdup("");
	if (!new->backup)
	{
		free(new);
		return (0);
	}
	if (lst->head)
	{
		temp = lst->head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		lst->before = temp;
	}
	else
	{
		lst->head = new;
		lst->before = 0;
	}
	lst->cur = new;
	lst->cur->next = 0;
	return (1);
}

char	*read_file(t_list *lst)
{
	int		read_size;
	char	buf[BUFFER_SIZE + 1];

	while(!ft_strchr(lst->cur->backup, '\n'))
	{
		read_size = read(lst->cur->fd, buf, BUFFER_SIZE);
		if (read_size == -1 || (read_size == 0 && !lst->cur->backup))
		// if (read_size == -1 || read_size == 0)
			return (0);
		else if (read_size == 0 && lst->cur->backup)
			break;
 		buf[read_size] = '\0';
 		lst->cur->backup = ft_strjoin(lst->cur->backup, buf);
		if (!lst->cur->backup)
		{
			remove_node(lst);
			return (0);
		}
	}
	return (lst->cur->backup);
}

char	*make_str(t_list *lst)
{
	char	*temp;
	char	*line;

	temp = lst->cur->backup;
	line = ft_strdup(lst->cur->backup);
	lst->cur->backup = ft_strdup(ft_strchr(lst->cur->backup, '\n') + 1);
	free(temp);
	temp = ft_strchr(line, '\n');
	// if ((temp - line + 1) < ft_strlen(line) && *(temp + 1) == '\0')
	// {
	// 	remove_node(lst);
	// 	return (line);
	// }	
	if (temp && (temp - line + 1) < ft_strlen(line))
		*(temp + 1) = '\0';
	else if (temp)
		line = ft_strjoin(line, "\0");
	if (!line)
	{
		remove_node(lst);
		return (0);
	}
	return (line);
}

char* remove_node(t_list*lst)
{
	t_node1	*temp;

	temp = lst->cur;
	if (lst->cur->backup)
	{
		free(lst->cur->backup);
		lst->cur->backup = 0;
	}
	if (lst->head == lst->cur)
	{
		lst->cur = lst->cur->next;
		lst->head = lst->cur;
	}
	else
		lst->before->next = lst->cur->next;
	free(temp);
	temp = 0;
	return (0);
}










// char	*make_str(char *line, t_list *lst)
// {
// 	char	*temp;
// 	char	*result;

// 	temp = line;
// 	result = ft_strdup(line);
// 	lst->cur->backup = ft_strdup(ft_strchr(line, '\n') + 1);
// 	free(temp);
// 	temp = ft_strchr(result, '\n');	
// 	if (temp && (temp - result + 1) < ft_strlen(result))
// 		*(temp + 1) = '\0';
// 	else if (temp)
// 		result = ft_strjoin(result, "\0");
// 	if (!result)
// 	{
// 		remove_node(lst);
// 		return (0);
// 	}
// 	return (result);
// }