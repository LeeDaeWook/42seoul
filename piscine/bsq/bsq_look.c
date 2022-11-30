/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_io_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:31:45 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/20 07:35:01 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#define X 0
#define Y 1
#define MAX 2
#define BOX 2
#define EMPTY 0
#define BLOCK 1

int	get_min(int a, int b, int c)
{
	if (a > b)
		return (b * (b <= c) + c * (c < b));
	else
		return (a * (a <= c) + c * (c < a));
}

int	**sol_map(int	**map, int row, int col)
{
	int	i;
	int	j;
	int t;

	i = 0;
	while (++i < row)
	{
		j = 0;
		while (++j < col)
		{

			t = get_min(map[i - 1][j - 1],map[i][j - 1], map[i - 1][j]);
			if (map[i][j] != 0)
				map[i][j] = t + 1;
		}
	}
	return (map);
}

void	print_answer(char **table, int row, int col)
{
	int		i;
	int		j;
	char	*onerow;

	onerow = (char *)malloc(sizeof(char) * col);
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			onerow[j] = table[i][j];
			j++;
		}
		onerow[j++] = '\n';
		write(1, onerow, col + 1);
		i++;
	}
	free(onerow);
}

void	print_answer2(int **table, int row, int col)
{
	int		i;
	int		j;
	char	now;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			now = table[i][j] + '0';
			write(1, &now, 1);
			if (j == col - 1)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			j++;
		}
		i++;
	}
}

int	get_max(int **map, int row, int col)
{
	int	i;
	int	j;
	int	max;

	max = 1;
	i = 0;
	while (++i < row)
	{
		j = 0;
		while (++j < col)
		{
			if (map[i][j] > max)
				max = map[i][j];
		}
	}
	return (max);
}

int *get_maxindex(int **map, int row, int col, int max)
{
	int	i;
	int	j;
	int	*mi;
	int	flag;

	i = -1;
	flag = 0;
	mi = (int *)malloc(sizeof(int) * 3);
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (map[i][j] == max)
			{
				mi[Y] = i - max + 1;
				mi[X] = j - max + 1;
				flag = 1;
			}
			if (flag)
				break ;
		}
	}
	mi[MAX] = max;
	return (mi);
}

int	pos_check(int i, int j, int *mi)
{
	if (i < mi[Y])
		return (0);
	if (j < mi[X])
		return (0);
	if (i >= mi[Y] + mi[MAX])
		return (0);
	if (j >= mi[X] + mi[MAX])
		return (0);
	return (1);
}

char	**mk_answer(int **map, int *pos, int *mi, char *mark)
{
	int		i;
	int		j;
	char	**out;

	out = (char **)malloc(sizeof(char *) * pos[Y]);
	i = -1;
	while (++i < pos[Y])
		out[i] = (char *)malloc(sizeof(char) * pos[X]);
	i = -1;
	while (++i < pos[Y])
	{
		j = -1;
		while (++j < pos[X])
		{
			if (pos_check(i, j, mi))
			   out[i][j] = mark[BOX];
			else if (map[i][j] == 0)
				out[i][j] = mark[BLOCK];
			else
				out[i][j] = mark[EMPTY];
		}
	}
	return (out);
}

void free_arr2(void **arr, int row)
{
	int	i;

	i = -1;
	while (++i < row)
		free(arr[i]);
	free(arr);
}

void print_map(int **map, int row, int col, char *mark)
{
	char	**answer;
	int		max;
	int		*mi;
	int		pos[2];

	max = get_max(map, row, col);
	mi = get_maxindex(map, row, col, max);
	pos[X] = col;
	pos[Y] = row;
	answer = mk_answer(map, pos, mi , mark);
	//printf("%s\n",mark); ???
	print_answer(answer, row, col);
	free(mi);
	free_arr2((void **)answer, row);
}

int	ft_strlen_check_val(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\n')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= sign;
	return (result);
}

int	total_line(char *argv, int line, int first_line)
{
	char	*buf;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (i++ <= first_line)
		read(fd, &buf, 1);
	buf = (char*)malloc(sizeof(char) * (line + 1));
	i = 0;
	while (read(fd, buf, line + 1))
		i++;
	close(fd);
	return (i);
}

int	get_first_row(char *argv)
{
	int		first_line;
	int		fd;
	char	buf;

	first_line = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buf, 1) && buf != '\n')
			first_line++;
	close(fd);
	return (first_line);
}

int	ft_line_len(char *argv, int first_line)
{
	int		line;
	int		fd;
	char	buf;
	int		i;

	line = 0;
	i = 0;
	fd = open(argv, O_RDONLY);
	while (i++ <= first_line)
		read(fd, &buf, 1);
	while (read(fd, &buf, 1) && buf != '\n')
			line++;
	close(fd);
	return (line);
}

int	overlap_n_count(char *argv, int count)
{
	int		j;
	char	buf[10];
	int		flag;
	int		fd;

	flag = 1;
	fd = open(argv, O_RDONLY);
	read(fd, buf, 10);
	if (ft_strlen(buf) != (count + 3))
		flag = 0;
	while (buf[count] != '\n')
	{
		j = count + 1;
		while (buf[j] != '\n')
		{
			if (buf[count] == buf[j++])
				flag = 0;
		}
		count++;
	}
	close(fd);
	return (flag);
}

char	*check_cond(char *argv, int line_count, int line_count2)
{
	char	*buf;
	char	*cond_char;
	int		fd;
	int		count;

	fd = open(argv, O_RDONLY);
	count = 0;
	while (line_count > 0)
	{	
		count++;
		line_count /= 10;
	}
	buf = (char*)malloc(sizeof(char) * count);
	read(fd, buf, count);
	if (!overlap_n_count(argv, count))
		return (0);
	if (ft_atoi(buf) != line_count2) // 조건에 명시된 줄수와 실제 줄수가 다를 경우
		return (0);
	count = 0;
	cond_char = (char*)malloc(sizeof(char) * 3);
	while (read(fd, &buf[0], 1) && buf[0] != '\n')
		cond_char[count++] = buf[0];
	close(fd);
	return (cond_char);
}

int	*int_arr(char *buf, int line_len, char *cond_char)
{
	int	i;
	int	*input_int;

	i = 0;
	input_int = (int*)malloc(sizeof(int) * line_len);
	while (i < line_len)
	{
		if (cond_char[0] == buf[i])
			input_int[i] = 1;
		else if (cond_char[1] == buf[i])
			input_int[i] = 0;
		i++;
	}
	return (input_int);
}

// 맵의 이상한 값 체크
int check_in(char *cond, char *buf, int line_len)
{
	int	i;

	i = 0;
	while (i < line_len)
	{
		if (buf[i] != cond[0] && buf[i] != cond[1])
			return (-1);
		i++;
	}
	return (0);
}

// 라인적은거 & 맵의 이상한값 에러로 리턴
int check_val(char *buf, char *cond, int line_len)
{
	if (ft_strlen_check_val(buf) < line_len)
		return (-1);
	if (check_in(cond, buf, line_len))
		return (-1);
	return (0);
}

int	into_map(int fd, char *argv, int **input_int)
{
	char		*buf;
	int			line_count;
	char		*cond_char;
	int			line_len;
	int			idx;

	line_len = ft_line_len(argv, get_first_row(argv));
	line_count = total_line(argv, line_len, get_first_row(argv));
	cond_char = check_cond(argv, line_count, line_count);
	if (cond_char == 0)
		return (-1);
	idx = 0;
	buf = (char*)malloc(sizeof(char) * line_len);
	while (idx < line_count)
	{
		if (idx == 0)
			read(fd, buf, get_first_row(argv) + 1);
		read(fd, buf, line_len);
		if (check_val(buf, cond_char, line_len) == -1) // 한줄 유효성 검사
			return (-1);
		input_int[idx] = int_arr(buf, line_len, cond_char);
		read(fd, buf, 1); // 개행 무시
		idx++;
	}
	return (0);
}


int	first_line_len(char *argv)
{
	int		first_line;
	int		fd;
	char	buf;

	first_line = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buf, 1) && buf != '\n')
			first_line++;
	close(fd);
	return (first_line);
}

void	ft_stdin()
{
	int		fd;
	char	buf;

	fd = open("test.txt", O_CREAT|O_RDWR|O_TRUNC, 0666);
	if (fd < 0)
		exit(-1);
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
	close(fd);
}


void	main_loop(char *argv, int *i)
{
	int	fd;
	int	**input_int;
	int	line_len;
	int	line_count;

	if ((fd = open(argv, O_RDONLY)) == -1)
		exit(1);
	else
	{
		line_len = ft_line_len(argv, get_first_row(argv)); 
		line_count = total_line(argv, line_len, get_first_row(argv));
		input_int = (int**)malloc(sizeof(int*) * line_count);
		if (into_map(fd, argv, input_int) == -1) //into map return 받아서 에러 면 넘김
		{
			(*i)++;
			write(2, "map error\n", 10); 
			return ;
		}
	}
	input_int = sol_map(input_int, line_count, line_len);
	print_map(input_int, line_count, line_len, check_cond(argv, line_count, line_count));
	(*i)++;
	close(fd);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		ft_stdin();
		argv[0] = "test.txt";
	}
	if (argc != 1)
		i = 1;
	while (i < argc)
		main_loop(argv[i], &i);
	return (0);
}
