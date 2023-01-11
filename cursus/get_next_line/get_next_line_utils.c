char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	chr;

	str = (char *)s;
	chr = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == chr)
			return (str);
		str++;
	}
	if (*str == '\0' && chr == '\0')
		return (str);
	return (0);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*cp_src;

	src_len = ft_strlen(src);
	cp_src = malloc(sizeof(char) * src_len);
	if (!cp_src)
		return (0);
	while (*src)
		*cp_src++ = *src++;
	cp_src = cp_src - src_len;
	return (cp_src);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

size_t	ft_copy(char *dest, char *src, size_t size, size_t dest_len)
{
	size_t	src_len;

	src_len = 0;
	if (size > dest_len)
	{
		while (*src != '\0' && (src_len + 1) < (size - dest_len))
		{
			*dest++ = *src++;
			src_len++;
		}
		*dest = '\0';
	}
	while (*src != '\0')
	{
		src_len++;
		src++;
	}
	return (src_len);
}

size_t	ft_strlcat(char*dest, const char*src, size_t size)
{
	unsigned int	src_len;
	unsigned int	dest_len;

	src_len = 0;
	dest_len = 0;
	while (*dest != '\0')
	{
		dest++;
		dest_len++;
	}
	src_len = ft_copy(dest, (char *)src, size, dest_len);
	if (size <= dest_len)
		return (src_len + size);
	return (dest_len + src_len);
}

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
