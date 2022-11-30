/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:41:18 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/12 19:14:25 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_isalpha(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

int	ft_isalpha(char *str)
{
	int	flag;
	int	len;

	flag = 0;
	len = ft_count_isalpha(str);
	while (*str != '\0')
	{
		if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
			flag++;
		str++;
	}
	if (flag == len)
		return (1);
	return (0);
}
