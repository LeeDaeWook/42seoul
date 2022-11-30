#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
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

void	int_arr(char **input, int line_count, int line_len, char *cond_char)
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

}

void	get_first_row(char *cond)
{
	int		first_line_len;
	char	buf;

	first_line_len = 0;
	while (read(0, &buf, 1) && buf != '\n')
		cond[first_line_len++] = buf;
	cond[first_line_len] = '\0';
	//return (first_line_len);
}

char	*ft_line_len(int *line_len)
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
	get_first_row(cond);
	input[0] = ft_line_len(&line_len);		
	i = 1;
	while (ft_read(input, i, line_len))
			i++;
	close(0);
	cond_char = check_cond_stdin(cond, i);
	int_arr(input, i, line_len, cond_char);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;

	(void) fd;
	(void) argv;

	i = 1;
	if (argc == 1)
		ft_stdin();	
	return (0);
}
