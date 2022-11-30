/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:30:39 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/20 11:30:48 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	into_map(int fd, char *argv, int **input_int)
{
	char		*buf;
	int			line_count;
	char		*cond_char;
	int			line_len;
	int			idx;

	line_len = ft_line_len(argv, get_first_row(argv)); 
	line_count = total_line(argv, line_len, get_first_row(argv));
	if ((cond_char = check_cond(argv, line_count, line_count)) == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	idx = 0;
	buf = (char*)malloc(sizeof(char) * line_len);
	while (idx < line_count)
	{
		if (idx == 0)
			read(fd, buf, get_first_row(argv) + 1);
		read(fd, buf, line_len);
		input_int[idx] = int_arr(buf, line_len, cond_char);
		read(fd, buf, 1); // 개행 무시
		idx++;
	}
	close(fd);

	int a;
	int b;
	a = 0;
	while (a < line_count)
	{
		b = 0;
		while (b < line_len)
		{
			printf("%d ", input_int[a][b]);
			b++;
		}
		printf("\n");
		a++;
	}		
}
