/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:37:26 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/15 20:01:44 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	advanced_sort(int str_count, char **tab, int (*cmp)(char *, char *))
{
	int		j;
	char	*temp;

	j = 0;
	while (str_count > j + 1)
	{
		if ((*cmp)(tab[j], tab[j + 1]) > 0)
		{
			temp = tab[j + 1];
			tab[j + 1] = tab[j];
			tab[j] = temp;
			j = -1;
		}
		j++;
	}
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	str_count;

	str_count = 0;
	while (tab[str_count] != 0)
		str_count++;
	advanced_sort(str_count, tab, cmp);
}
