/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:56:49 by heynard           #+#    #+#             */
/*   Updated: 2018/01/31 12:56:51 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static void				copy_things(char **final, t_blist *tmp,
									t_bracket_functions *tools)
{
	if (tools->result[tools->i])
	{
		tools->tofree = final[tools->pos];
		final[tools->pos] = ft_strjoin(final[tools->pos],
							tools->result[tools->i]);
		ft_strdel(&(tools->tofree));
	}
	tools->i++;
	tools->tofree = final[tools->pos];
	final[tools->pos] = ft_strjoin(final[tools->pos], tmp->r_bracket[0]);
	ft_strdel(&(tools->tofree));
}

static void				inner_fill_final(char **final, t_biglist *b,
										t_bracket_functions *tools)
{
	t_blist				*tmp;

	tmp = b->blist;
	while (tmp->tmp)
		tmp = tmp->next;
	copy_things(final, tmp, tools);
	if (b->next)
		inner_fill_final(final, b->next, tools);
	if (tools->up || b->next == NULL)
	{
		tmp->tmp = 1;
		tools->up = 0;
	}
	if (tmp->next == NULL && tmp->tmp)
	{
		tmp = b->blist;
		while (tmp)
		{
			tmp->tmp = 0;
			tmp = tmp->next;
		}
		tools->up = 1;
	}
}

static t_blist			*check_to_up(char **final, t_blist *tmp,
									t_bracket_functions *tools)
{
	if (tools->result[tools->i])
	{
		tools->tofree = final[tools->pos];
		final[tools->pos] = ft_strjoin(final[tools->pos],
									tools->result[tools->i]);
		ft_strdel(&(tools->tofree));
	}
	if (tools->up)
	{
		tmp = tmp->next;
		tools->up = 0;
	}
	tools->pos++;
	return (tmp);
}

char					**fill_final(char **final, size_t pos,
										char **result, t_biglist *b)
{
	t_bracket_functions	tools;
	t_blist				*tmp;

	tools.up = 0;
	tools.pos = pos;
	tools.result = result;
	tmp = b->blist;
	while (tmp)
	{
		tools.i = 0;
		if (tools.result[tools.i])
			final[tools.pos] = ft_strdup(tools.result[tools.i]);
		tools.i++;
		tools.tofree = final[tools.pos];
		final[tools.pos] = ft_strjoin(final[tools.pos], tmp->r_bracket[0]);
		ft_strdel(&(tools.tofree));
		if (b->next)
			inner_fill_final(final, b->next, &tools);
		else
			tools.up = 1;
		tmp = check_to_up(final, tmp, &tools);
	}
	return (final);
}