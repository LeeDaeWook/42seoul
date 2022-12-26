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
