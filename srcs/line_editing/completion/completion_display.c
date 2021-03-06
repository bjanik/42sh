/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:37:48 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/14 11:25:44 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	display_next_match(t_comp *comp, t_input *input, char *copy)
{
	int	i;
	int	cursor;

	cursor = comp->init_c_pos + ft_strlen(copy);
	paste_str_in_buffer(copy, input);
	handle_home(input);
	apply_termcaps("ce");
	display_buffer(input, 0);
	i = input->buffer_len;
	while (i-- > cursor)
		handle_arrow_left(input);
	return (0);
}

static void	remove_previous_match(t_comp *comp, t_input *input)
{
	int	i;

	comp->current = (!comp->current) ? comp->matches : comp->current->next;
	(!comp->current) ? comp->current = comp->matches : 0;
	if (comp->count)
		cut_from_buffer(input, input->cursor_pos,
						comp->init_c_pos, ft_strlen(comp->comp_str));
	i = input->cursor_pos;
	while (i-- > comp->init_c_pos)
		handle_arrow_left(input);
}

int			completion_display(t_comp *comp, t_input *input)
{
	char	*str;

	str = (char*)comp->matches->content;
	if (comp->nb_matches == 1)
	{
		if (comp->prefix[0] == '$')
			comp->comp_str = ft_strdup(str + comp->basename_len);
		else
			comp->comp_str = ft_strdup(str + comp->basename_len);
		paste_str_in_buffer(comp->comp_str, input);
		display_line(input, input->cursor_pos + ft_strlen(comp->comp_str));
		input->state = STANDARD;
		reset_completion_data(comp);
	}
	else if (comp->nb_matches)
	{
		remove_previous_match(comp, input);
		(comp->comp_str) ? clear_lines(input, comp->comp_str) : 0;
		ft_strdel(&comp->comp_str);
		str = (char*)comp->current->content;
		comp->comp_str = ft_strdup(str + comp->basename_len);
		display_next_match(comp, input, comp->comp_str);
		comp->count++;
	}
	return (0);
}
