/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_external.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:59:38 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/22 15:36:54 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"
#include "shell_signal.h"
#include "shell.h"
#include "shell_errmsg.h"

int			launch_external(char *const bin_path, char **argv, t_env *env,
		t_bool is_child)
{
	pid_t			father;

	if (bin_path && argv && env && !recreate_env_array(env))
	{
		father = (is_child) ? 0 : fork();
		if (!father)
		{
			set_shell_sigmode(e_shell_sigmode_all_default);
			execve(bin_path, argv, env->env_array);
			execve_error(bin_path, argv, env->env_array);
			exit(-1);
		}
		else if (0 < father)
			return (wait_for_instance(father));
		else
			ft_dprintf(2, "42sh: %s: failed to fork\n", argv[0]);
	}
	return (1);
}
