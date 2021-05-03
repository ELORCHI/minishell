/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:33:31 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/03 14:39:41 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_exit(t_builtin_vars var, int *retv)
{
	int	number;

	number = 0;
	if (ft_size_args(var.args) == 0)
		exit(0);
	else if (ft_size_args(var.args) == 1 && var.args[1] != NULL && ft_only_digits(var.args[1]))
	{
		number = ft_atoi(var.args[1]);
		//free alllllll
		exit(number);
	}
	else
		ft_exit_helper(var, retv);
}

void	ft_exit_helper(t_builtin_vars var, int *retv)
{
	int number;

	if (var.args[1] != NULL && !ft_only_digits(var.args[1]))
	{
		number = 255;
		write(1, "MiniShell: exit: ", 17);
		write(1, var.args[1], ft_strlen(var.args[1]));
		write(1, ": numeric argument required", 27);
		exit(number);
	}
	else
	{
		number = 0;
		*retv = 1;
		write(1, "MiniShell: exit: too many arguments", 35);
	}
}
