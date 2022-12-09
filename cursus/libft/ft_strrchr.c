/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:01:09 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/01 20:23:02 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*first_addr;

	str = (char *)s;
	first_addr = str;
	while (*str != '\0')
		str++;
	if (*str == '\0' && c == '\0')
		return (str);
	while (str != first_addr)
	{
		if (*str == c)
			return (str);
		str--;
	}
	return (0);
}
