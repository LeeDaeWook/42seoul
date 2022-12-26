/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:19:54 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/15 18:58:09 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	sort(int str_count, char **tab)
{
	int		j;
	char	*temp;

	j = 0;
	while (str_count > j + 1)
	{
		if (cmp(tab[j], tab[j + 1]) > 0)
		{
			temp = tab[j + 1];
			tab[j + 1] = tab[j];
			tab[j] = temp;
			j = -1;
		}
		j++;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	str_count;

	str_count = 0;
	while (tab[str_count] != 0)
		str_count++;
	sort(str_count, tab);
}
