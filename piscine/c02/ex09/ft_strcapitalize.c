/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:01:24 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/02 22:50:02 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_uppercase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (i == 0)
				str[i] -= 32;
			else if (str[i - 1] <= 47 || (str[i - 1] >= 58 && str[i - 1] \
						<= 64) || (str[i - 1] >= 91 && str[i - 1] <= 96) \
					|| str[i - 1] >= 123)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}

char	*ft_lowercase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
				*(str + i) += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	str = ft_lowercase(str);
	str = ft_uppercase(str);
	return (str);
}
