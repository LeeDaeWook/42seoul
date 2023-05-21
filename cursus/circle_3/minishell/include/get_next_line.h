/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:33:42 by daewoole          #+#    #+#             */
/*   Updated: 2023/04/04 00:01:28 by kyeonkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node {
	int				fd;
	char			*backup;
	struct s_node	*next;
}	t_n;

char			*get_next_line(int fd);
int				find_node(int fd, t_n **head, t_n **cur, t_n **before);
int				gnl_add_node(t_n **head, t_n **cur, t_n **before);
char			*read_file(t_n **head, t_n **cur, t_n **before);
char			*make_str(t_n **head, t_n **cur, t_n **before);
void			remove_node(t_n **head, t_n **cur, t_n **before);

#endif
