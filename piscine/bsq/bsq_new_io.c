#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>

/*
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
*/
/*
int	total_line(char *argv, int line, int first_line)
{
	char	*buf;
	int		i;
	int		fd;
	int		ret_val;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (i++ <= first_line)
		read(fd, &buf, 1);
	buf = (char*)malloc(sizeof(char) * (line + 1));
	i = 0;
	while ((ret_val = read(fd, buf, line + 1)) != 0)
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
*/
/*
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
*/
/*
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
*/
/*
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
*/
/*
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
*/
/*
void	ft_stdin()
{
	int		fd;
	char	buf;
	int		**input_int;
	int		line_len;
	int		line_count;

	fd = open("test.txt", O_CREAT|O_RDWR|O_TRUNC, 0666);
	if (fd < 0)
		exit(-1);
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
	close(fd);
	line_len = ft_line_len("test.txt", get_first_row("test.txt"));
	line_count = total_line("test.txt", line_len, get_first_row("test.txt"));
	input_int = (int**)malloc(sizeof(int*) * line_count);
	fd = open("test.txt", O_RDONLY);
	into_map(fd, "test.txt", input_int);
}
*/
/*
int	main(int argc, char *argv[])
{
	int	fd;
	int	i;
	int	**input_int;
	int	line_len;
	int	line_count;

	i = 1;
	if (argc == 1)
		ft_stdin();
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			exit(1);
		else
		{
			line_len = ft_line_len(argv[i], get_first_row(argv[i]));
			line_count = total_line(argv[i], line_len, get_first_row(argv[i]));
			input_int = (int**)malloc(sizeof(int*) * line_count);
			into_map(fd, argv[i], input_int);
		}
		i++;
	}	
	return (0);
}
*/
