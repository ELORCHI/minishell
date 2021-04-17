/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:51:51 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/17 17:08:52 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int		format_terminal(t_termios *orig)
{
	t_termios	term;

	if (!get_termios(&term))
	{
		*orig = term;
		term.c_lflag &= ~(ICANON | ECHOCTL);
		term.c_iflag &= (BRKINT | ICRNL | IGNBRK | IGNCR
				| INLCR | INPCK | ISTRIP | IXON | PARMRK);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (!set_termios(&term, TCSAFLUSH))
			return (0);
		return (-1);
	}
	return (-1);
}

int		rest_terminal(t_termios *orig)
{
	if (!set_termios(orig, TCSANOW))
		return (0);
	return (-1);
}
