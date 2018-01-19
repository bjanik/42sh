/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 20:18:42 by bjanik            #+#    #+#             */
/*   Updated: 2017/10/19 15:58:47 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			is_operator(const char *token)
{
	int	i;

	i = 2;
	while (g_op_list[++i])
	{
		if (!ft_strcmp(g_op_list[i], token))
			return (i);
	}
	return (-1);
}