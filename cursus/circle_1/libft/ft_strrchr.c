/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:01:09 by daewoole          #+#    #+#             */
/*   Updated: 2022/12/26 21:23:17 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	char			*first_addr;
	unsigned char	chr;

	str = (char *)s;
	first_addr = str;
	chr = (unsigned char)c;
	while (*str != '\0')
		str++;
	if (*str == '\0' && chr == '\0')
		return (str);
	while (str != first_addr)
	{
		if (*str == chr)
			return (str);
		str--;
	}
	if (*str == chr)
		return (str);
	return (0);
}
