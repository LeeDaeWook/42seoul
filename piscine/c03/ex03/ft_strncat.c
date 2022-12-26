/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:21:24 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/03 18:23:38 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	int				j;
	unsigned int	count;

	i = 0;
	j = 0;
	count = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && count < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
		count++;
	}
	dest[i] = '\0';
	return (dest);
}
