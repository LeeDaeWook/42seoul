/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:29:52 by daewoole          #+#    #+#             */
/*   Updated: 2022/10/20 11:30:17 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*int_arr(char *buf, int line_len, char *cond_char)
{
	int	i;
	int	*input_int;

	i = 0;
	input_int = (int*)malloc(sizeof(int) * line_len);
	while (i < line_len)
	{
		if (cond_char[0] == buf[i])
			input_int[i] = 1;
		else if (cond_char[1] == buf[i])
			input_int[i] = 0;
		i++;
	}
	return (input_int);
}
