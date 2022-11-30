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
