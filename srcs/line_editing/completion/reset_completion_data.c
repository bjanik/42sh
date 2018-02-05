/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_completion_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:55:42 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/03 18:43:50 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	del_matches(void *matches, size_t size)
{
	(void)size;
	ft_memdel((void**)&matches);
}

int			reset_completion_data(t_comp *comp)
{
	ft_strdel(&comp->prefix);
	ft_strdel(&comp->dirname);
	ft_strdel(&comp->basename);
	comp->basename_len = 0;
	ft_lstdel(&comp->matches, del_matches);
	comp->current = NULL;
	comp->nb_matches = 0 ;
	comp->search_location = 0;
	comp->init_pos = -1;
	return (0);

}
