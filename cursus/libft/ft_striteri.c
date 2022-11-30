/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:51:15 by daewoole          #+#    #+#             */
/*   Updated: 2022/11/24 20:01:04 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	ft_strupcase(unsigned int i, char *s)
{
	(void) i;
	if (*s >= 'a' && *s <= 'z')
		*s -= 32;
}

#include <stdio.h>

int main(void)
{
	char s[] = "abcdezzzzz";
	ft_striteri(s, ft_strupcase);
	printf("%s\n", s);

	return (0);
}
*/
