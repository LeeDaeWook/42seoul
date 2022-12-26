/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:23:54 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/03 18:27:18 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	if (!(*to_find))
		return (str);
	while (*(str + j) != '\0')
	{
		if (*(to_find + i) == *(str + j))
		{
			if (i == 0)
				temp = j;
			i++;
			if (*(to_find + i) == '\0')
				return (str + temp);
		}
		else
			i = 0;
		j++;
	}
	return (0);
}
