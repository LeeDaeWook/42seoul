/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:23:11 by daewoole          #+#    #+#             */
/*   Updated: 2023/01/19 14:24:50 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	int				fd;
	char			*backup;
	struct s_node	*next;
}	t_n;

char			*get_next_line(int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *src);
unsigned int	ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
int				find_node(int fd, t_n **head, t_n **cur, t_n **before);
int				add_node(t_n **head, t_n **cur, t_n **before);
char			*read_file(t_n **head, t_n **cur, t_n **before);
char			*make_str(t_n **head, t_n **cur, t_n **before);
void			remove_node(t_n **head, t_n **cur, t_n **before);

#endif
