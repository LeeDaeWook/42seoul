/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:38:08 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/19 14:36:19 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

char	*get_next_line(int fd)
{
	static t_n	*head;
	t_n			*cur;
	t_n			*before;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (!find_node(fd, &head, &cur, &before))
	{
		if (!gnl_add_node(&head, &cur, &before))
			return (0);
	}
	cur->fd = fd;
	line = read_file(&head, &cur, &before);
	if (line && ft_strchr(line, '\n'))
		line = make_str(&head, &cur, &before);
	else if (line && ft_strchr(line, '\0'))
	{
		line = ft_strdup(line);
		remove_node(&head, &cur, &before);
	}
	if (!line && cur->backup)
		remove_node(&head, &cur, &before);
	return (line);
}

int	find_node(int fd, t_n **head, t_n **cur, t_n **before)
{
	t_n	*temp;

	*cur = 0;
	*before = 0;
	temp = *head;
	while (temp)
	{
		if (fd == temp->fd)
		{
			*cur = temp;
			return (1);
		}
		*before = temp;
		temp = temp->next;
	}
	return (0);
}

int	gnl_add_node(t_n **head, t_n **cur, t_n **before)
{
	t_n	*new;
	t_n	*temp;

	new = (t_n *)malloc(sizeof(t_n));
	if (!new)
		return (0);
	new->backup = ft_strdup("");
	if (!new->backup)
	{
		free(new);
		return (0);
	}
	if (*head)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		*before = temp;
	}
	else
		*head = new;
	*cur = new;
	(*cur)->next = 0;
	return (1);
}

char	*read_file(t_n **head, t_n **cur, t_n **before)
{
	int		read_size;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	while (!ft_strchr((*cur)->backup, '\n'))
	{
		read_size = read((*cur)->fd, buf, BUFFER_SIZE);
		if (read_size == -1 || (read_size == 0 && (*cur)->backup[0] == '\0'))
			return (0);
		else if (read_size == 0 && (*cur)->backup)
			break ;
		buf[read_size] = '\0';
		temp = (*cur)->backup;
		(*cur)->backup = ft_strjoin((*cur)->backup, buf);
		free(temp);
		if (!(*cur)->backup)
		{
			remove_node(head, cur, before);
			return (0);
		}
	}
	return ((*cur)->backup);
}

char	*make_str(t_n **head, t_n **cur, t_n **before)
{
	char	*temp;
	char	*line;
	int		i;

	temp = (*cur)->backup;
	line = ft_strdup((*cur)->backup);
	(*cur)->backup = ft_strdup(ft_strchr((*cur)->backup, '\n') + 1);
	if (!(*cur)->backup)
	{	
		remove_node(head, cur, before);
		free(temp);
		free(line);
		return (0);
	}
	free(temp);
	i = 0;
	while (line && line[i] != '\n')
		i++;
	temp = line;
	line[i + 1] = '\0';
	line = ft_strdup(line);
	free(temp);
	if (!line)
		remove_node(head, cur, before);
	return (line);
}
