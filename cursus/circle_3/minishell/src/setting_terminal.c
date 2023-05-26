/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_terminal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:01:44 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/03/31 16:02:01 by kyeonkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_termios(void)
{
	struct termios	termios_setting;

	tcgetattr(STDIN_FILENO, &termios_setting);
	termios_setting.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &termios_setting);
}

void	ft_reset_termios(void)
{
	struct termios	termios_setting;

	tcgetattr(STDIN_FILENO, &termios_setting);
	termios_setting.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &termios_setting);
}
