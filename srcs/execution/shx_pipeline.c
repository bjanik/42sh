/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shx_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:24:45 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/22 14:40:37 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "shell.h"

int	shx_pipeline(struct s_sh_pipeline *const pipeline)
{
	t_bsh *const	bsh = get_shell_data();
	int				ret;

	if (bsh && pipeline != NULL)
	{
		ret = shx_pipe_sequence(pipeline->pipe_sequence);
		bsh->exit_status = pipeline->bang ? !ret : ret;
		return (bsh->exit_status);
	}
	return (0);
}
