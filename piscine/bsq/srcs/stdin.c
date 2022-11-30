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
