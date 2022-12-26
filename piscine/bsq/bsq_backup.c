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
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void	put_err(char *argv)
{
		write(2, "ft_cat: ", 8);
		write(2, basename(argv), ft_strlen(basename(argv)));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(1, "\n", 1);
}

*/

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

char	*check_cond(char *argv, int line_count)
{
	char	*buf;
	char	*cond_char;
	int		fd;
	int		count;
	int		ret_val;

	fd = open(argv, O_RDONLY);
	count = 0;
	while (line_count > 0)
	{
		count++;
		line_count /= 10;
	}
	buf = (char*)malloc(sizeof(char) * count);
	read(fd, buf, count);
	count = 0;
	cond_char = (char*)malloc(sizeof(char) * 3);
	while ((ret_val = read(fd, &buf[0], 1)) != 0 && buf[0] != '\n')
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

void	into_map(int fd, char *argv[], int i, int **input_int)
{
	char		*buf;
	int			line_count;
	char		*cond_char;
	int			line_len;
	int			idx;

	line_len = ft_line_len(argv[i], get_first_row(argv[i])); 
	line_count = total_line(argv[i], line_len, get_first_row(argv[i]));
	cond_char = check_cond(argv[i], line_count);
	idx = 0;
	buf = (char*)malloc(sizeof(char) * line_len);
	while (idx < line_count)
	{
		if (idx == 0)
			read(fd, buf, get_first_row(argv[i]) + 1);
		read(fd, buf, line_len);
		input_int[idx] = int_arr(buf, line_len, cond_char);
		read(fd, buf, 1);
		idx++;
	}	
	
	/*
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
	*/
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

void	int_arr_stdin(char **input, int line_count, int line_len, char *cond_char)
{
	int	**input_int;
	int	i;
	int	j;

	input_int = (int**)malloc(sizeof(int*) * line_count);
	i = 0;
	while (i < line_count)
	{
		input_int[i] = (int*)malloc(sizeof(int) * line_len);
		j = 0;
		while (j < line_len)
		{
			if (cond_char[0] == input[i][j])
				input_int[i][j] = 1;
			else if (cond_char[1] == input[i][j])
				input_int[i][j] = 0;
			j++;
		}
		i++;
	}

	/*
	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (j < line_len)
		{
			printf("%d ", input_int[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}	
	*/
}

void	get_first_row_stdin(char *cond)
{
	int		first_line_len;
	char	buf;

	first_line_len = 0;
	while (read(0, &buf, 1) && buf != '\n')
		cond[first_line_len++] = buf;
	cond[first_line_len] = '\0';
}

char	*line_len_stdin(int *line_len)
{
	int		i;
	char	buf;
	char	*temp_arr;

	temp_arr = (char*)malloc(sizeof(char) * 100002);
	i = 0;
	while (read(0, &buf, 1) && buf != '\n')
	{
		temp_arr[i++] = buf;
		(*line_len)++;
	}
	return (temp_arr);
}

char	*check_cond_stdin(char *cond, int line_count)
{
	char	*cond_char;
	int		count;
	int		i;

	count = 0;
	while (line_count > 0)
	{
		count++;
		line_count /= 10;
	}
	cond_char = (char*)malloc(sizeof(char) * 3);
	i = 0;
	while (cond[count] != '\0')
	{
		cond_char[i] = cond[count];
		i++;
		count++;
	}
	return (cond_char);
}

int	ft_read(char **input, int i, int line_len)
{
	char	*buf;
	char	temp_buf;
	ssize_t	ret_val;

	buf = (char*)malloc(sizeof(char) * line_len);
	ret_val = read(0, buf, line_len);
	read(0, &temp_buf, 1);
	input[i] = buf;
	//if (ret_val != line_len)
	//	exit();
	return (ret_val);
}

void	ft_stdin()
{
	char	**input;
	char	cond[15];
	int		i;
	int		line_len;
	char	*cond_char;
	
	input = (char**)malloc(sizeof(char*) * 100000);
	get_first_row_stdin(cond);
	input[0] = line_len_stdin(&line_len);		
	i = 1;
	while (ft_read(input, i, line_len))
			i++;
	close(0);
	cond_char = check_cond_stdin(cond, i);
	int_arr_stdin(input, i, line_len, cond_char);
}

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
			//put_err(argv[i]);
			printf("error");
		else
		{
			line_len = ft_line_len(argv[i], get_first_row(argv[i])); 
			line_count = total_line(argv[i], line_len, get_first_row(argv[i]));
			input_int = (int**)malloc(sizeof(int*) * line_count);
			into_map(fd, argv, i, input_int);
		}
		i++;
		close(fd);
	}	
	return (0);
}
