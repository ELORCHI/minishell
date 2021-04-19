/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:45:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/19 13:40:49 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	delete_char(char **buff)
{
	int		len;
	char	*move_left;
	char	*del_one;

	len = ft_strlen(*buff);
	move_left = tgetstr("le", 0);
	del_one = tgetstr("dc", 0);
	if (len > 0)
	{
		(*buff)[len - 1] = '\0';
		tputs(move_left, 1, ft_putchar);
		tputs(del_one, 1, ft_putchar);
	}
}

void	clear_line(void)
{
	char	*start_line;
	char	*delete;

	start_line = tgetstr("cr", 0);
	delete = tgetstr("ce", 0);
	tputs(start_line, 1, ft_putchar);
	tputs(delete, 1, ft_putchar);
	write(1, "MiniShell $> ", 13);
}
