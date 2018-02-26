/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:02:54 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 22:36:39 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "execution.h"
#include "shell_errmsg.h"

static void	exit_badarg(char *arg)
{
	ft_putstr_fd("42sh: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

static int	exit_arg_check(char **args)
{
	if (args == NULL || args[0] == NULL)
	{
		shell_errmsg(e_shell_errmsg_inval, __FUNCTION__);
		return (1);
	}
	if (args[1] != NULL && args[2] != NULL)
	{
		shell_errmsg(e_shell_errmsg_tmarg, __FUNCTION__);
		return (1);
	}
	return (0);
}

int			builtin_exit(char **args, t_env *env)
{
	unsigned char	exit_value;

	(void)env;
	if (exit_arg_check(args))
		return (-1);
	if (args[1] == NULL)
		exit_value = 42;
	else if (string_is_digit(args[1]))
		exit_value = (unsigned char)ft_atoi(args[1]);
	else
	{
		exit_badarg(args[1]);
		exit_value = -1;
	}
	exit(exit_value);
}