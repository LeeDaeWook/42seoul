/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:43:40 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/26 21:18:16 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
