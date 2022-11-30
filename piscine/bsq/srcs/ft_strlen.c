int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\n')
		i++;
	return (i);
}
