/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:00:29 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/20 11:54:09 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	display_global_env(t_env_list const *env_list)
{
	while (env_list)
	{
		if (env_list->exportable == GLOBAL)
			if (env_list->name && env_list->value)
				ft_printf("%s=%s\n", env_list->name, env_list->value);
		env_list = env_list->next;
	}
	return (0);
}

int	display_local_global_env(t_env_list const *env_list)
{
	while (env_list)
	{
		if (env_list->name && env_list->value)
		{
			if (env_list->exportable == GLOBAL)
				ft_printf("exported ");
			ft_printf("%s=%s\n", env_list->name, env_list->value);
		}
		env_list = env_list->next;
	}
	return (0);
}

int	display_local_env(t_env_list const *env_list)
{
	while (env_list)
	{
		if (env_list->exportable == LOCAL)
			ft_printf("%s=%s\n", env_list->name, env_list->value);
		env_list = env_list->next;
	}
	return (0);
}
