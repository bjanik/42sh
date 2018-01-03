/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:11:12 by bjanik            #+#    #+#             */
/*   Updated: 2017/10/14 13:29:39 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	check_arg_opt(char *arg_opt, char *available_opts, char *options)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (arg_opt[++i])
	{
		if (!ft_strchr(available_opts, arg_opt[i]))
			return (arg_opt[i]);
		if (!ft_strchr(options, arg_opt[i]))
			options[j++] = arg_opt[i];
	}
	return (0);
}
