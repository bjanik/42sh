/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_preop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:08:25 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/01 15:58:05 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_ast/container_labels.h"
#include "s_container.h"
#include "libft.h"
#include <stdlib.h>

void	*create_pipeline_preop(void const *lex_value)
{
	struct s_container	*container;

	(void)lex_value;
	container = new_container(NULL, NULL, 0,
			e_ast_container_label_pipeline_preop);
	return (container);
}

t_bool	give_pipeline_preop(void *construct, void *sub_construct)
{
	struct s_container	*sub;
	struct s_container	*top;
	t_bool				ret;

	ret = FALSE;
	if (construct != NULL && sub_construct != NULL)
	{
		top = construct;
		sub = sub_construct;
		if (sub->label == e_ast_container_label_bang)
		{
			top->label = e_ast_container_label_bang;
			ret = TRUE;
		}
		if (ret == TRUE)
			destroy_container((void**)&sub);
	}
	return (ret);
}
