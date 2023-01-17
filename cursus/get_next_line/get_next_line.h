/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:33:42 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/16 10:37:10 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	int				fd;
	char			*backup;
	struct s_node	*next;
}	t_node1;

typedef struct s_list {
	t_node1	*head;
	t_node1	*cur;
	t_node1	*before;
}	t_list;

char			*get_next_line(int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *src);
unsigned int	ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
int				find_node(int fd, t_list *lst);
int				add_node(int fd, t_list *lst);
//char			*read_file(t_list *lst, char *buf);
char			*remove_node(t_list *lst);
//char			*make_str(t_list *lst, char *line, char *buf, char *temp);

char			*make_str(t_list *lst, char *line, char *buf);
char			*read_file(t_list *lst);

#endif