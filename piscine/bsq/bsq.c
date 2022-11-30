#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	long	l;
	int		i;
	int		sign;

	i = 0;
	l = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		l = l * 10 + (*str - '0');
		str++;
	}
	l *= sign;
	return ((int) l);
}

/*
void	put_err(char *argv)
{
		write(2, "ft_cat: ", 8);
		write(2, basename(argv), ft_strlen(basename(argv)));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(1, "\n", 1);
}
*/


char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *src, int n)
{
	int		src_len;
	char	*cp_src;
	int		i;

	src_len = 0;
	while (*(src + src_len))
		src_len++;
	cp_src = malloc(sizeof(char) * (src_len + 1));
	if (!cp_src)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		cp_src[i] = src[i];
		i++;
	}
	cp_src[i] = '\0';
	return (cp_src);
}

char	*check_cond(int *line_count)
{
	int		i;
	int		j;
	char	buf;
	char	*cond;
	char	first_line[10];

	cond = (char*)malloc(sizeof(char) * 3);
	i = 0;
	while (read(0, &buf, 1) != 0 && buf != '\n')
		first_line[i++] = buf;
	first_line[i] = '\0';
	j = 2;
	while (j >= 0)
	{
		cond[j--] = first_line[i - 1];
		i--;
	}
	*line_count = ft_atoi(ft_strdup(first_line, i));
	return (cond);
}

int	ft_line_len(char **input, int i)
{
	int		line;
	char	buf;
	char	first_line[100000];

	line = 0;
	while (read(0, &buf, 1) && buf != '\n')
	{
		first_line[line] = buf;
		line++;
	}
	input[i] = ft_strdup(first_line, line);
	return (line);
}

void	ft_read(char **input, int i, int line_len)
{
	char	*buf;
	char	temp_buf;

	buf = (char*)malloc(sizeof(char) * line_len);
	read(0, buf, line_len);
	read(0, &temp_buf, 1);
	input[i] = buf;
}

void	int_arr(char **input, int line_count, int line_len, char *cond)
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
			if (cond[0] == input[i][j])
				input_int[i][j] = 1;
			else if (cond[1] == input[i][j])
				input_int[i][j] = 0;
			j++;
		}
		i++;
	}

	/*
	
	printf("\n");

	i = 0;
	while (i < line_count)
	{	
		j = 0;
		while (j < line_len)
		{
			printf("%d ", input_int[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	*/
}

void	ft_stdin(void)
{
	int		line_count;
	char	**input;
	char	*cond;
	int		i;
	int		line_len;

	cond = check_cond(&line_count);	
	input = (char**)malloc(sizeof(char*) * line_count);
	i = 0;
	while (i < line_count)
	{
		if (i == 0)
			line_len = ft_line_len(input, i);
		else
			ft_read(input, i, line_len);
		i++;
	}
	int_arr(input, line_count, line_len, cond);
}

char	*check_cond_isargv(int fd, int *line_count)
{
	int		i;
	int		j;
	char	buf;
	char	*cond;
	char	first_line[10];

	cond = (char*)malloc(sizeof(char) * 3);
	i = 0;
	while (read(fd, &buf, 1) != 0 && buf != '\n')
		first_line[i++] = buf;
	j = 2;
	while (j >= 0)
	{
		cond[j--] = first_line[i - 1];
		i--;
	}
	*line_count = ft_atoi(ft_strdup(first_line, i));
	return (cond);
}

void	ft_read_isargv(int fd, char *input, int line_len)
{
	char	*buf;
	char	temp_buf;

	buf = (char*)malloc(sizeof(char) * line_len);
	read(fd, buf, line_len);
	read(fd, &temp_buf, 1);
	input = buf;
}

void	int_arr_isargv(int line_len, char *cond, int i, char *input)
{
	int	**input_int;
	int	j;

	input_int[i] = (int*)malloc(sizeof(int) * line_len);
	while (j < line_len)
	{
		if (cond[0] == input[j])
			input_int[i][j] = 1;
		else if (cond[1] == input[j])
			input_int[i][j] = 0;
		j++;
	}

	printf("\n");

	int k;
	k = 0;
	while (k < 9)
	{	
		j = 0;
		while (j < line_len)
		{
			printf("%d ", input_int[k][j]);
			j++;
		}
		k++;
		printf("\n");
	}

}

void	into_map(int fd, char *argv, int argc)
{
	char		*cond;
	int			line_count;
	int			line_len;
	int			i;
	char		*input;

	cond = check_cond_isargv(fd, &line_count);
	//printf("%s\n", cond_char);
	i = 0;
	while (i < line_count)
	{
		if (i == 0)
		{
			line_len = ft_line_len(input, i);
			int_arr_isargv(line_len, cond, i, input);
		}
		else
		{
			ft_read_isargv(fd, input, line_len);
			int_arr_isargv(line_len, cond, i, input);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;

	i = 1;
	if (argc == 1)
		ft_stdin();
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			put_err(argv[i]);
		else
		{
			into_map(fd, argv[i], argc);
		}
		i++;
		close(fd);
	}
	return (0);
}
