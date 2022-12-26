#include <stdlib.h>
#include <stdio.h>

int	str_len(char *str, char *charset, int k)
{
	int	strlen;

	strlen = 0;
	while (*(str + k) != charset[0] && *(str + k) != '\0')
	{
		strlen++;
		k++;
	}
	return (strlen + 1);
}

int	sep_len(char*charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
		i++;
	return (i);
}


int	str_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == charset[0])
			count++;
	}
	return (count);
}

int	split_len(char *str, char *charset)
{
	int total_len;
	int sep_len;

	total_len = 0;
	sep_len = 0;
	while (*(str + total_len) != charset[0])
		total_len++;
	while (charset[sep_len] != '\0')
		sep_len++;
	total_len += (sep_len * 2);
	return (total_len);
}


char	*ft_malloc(int size, char **strs, char *str_cat, char *sep)
{
	int	i;
	int	j;
	int	sep_len;
	int	strs_len;

	sep_len = 0;
	while (*(sep + sep_len))
		sep_len++;
	i = 0;
	strs_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			strs_len++;
			j++;
		}
		i++;
	}
	strs_len += sep_len * (size - 1);
	if (size <= 0) strs_len = 1;
	str_cat = (char*)malloc(sizeof(char) * strs_len);
	if (str_cat == 0) 
		return (0);
	return 
		(str_cat);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_cat;
	int 		i;
	int		j;
	int		k;


	//str_cat = ft_malloc(size, strs, str_cat, sep);
	str_len = 
	str_cat = (char*)malloc(sizeof(char) * strs_len);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str_cat[k++] = strs[i][j++];
		j = 0;
		while (i <= (size - 1) && sep[j])
			str_cat[k++] = sep[j++];
		i++;
	}
	str_cat[k] = '\0';
	return (str_cat);
}

int main()
{
	char *str_join[] = {"hello","my", "name", "is", "lee"};
	char sep[10] = "**@@@";
	int	size = 5;
	printf("str = hello, my, name, is, lee\t size = %d, sep = %s\n", size, sep);
	printf("%s\n", ft_strjoin(size, str_join, sep));
}
