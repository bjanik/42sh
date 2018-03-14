/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:42:28 by heynard           #+#    #+#             */
/*   Updated: 2018/01/17 16:42:29 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static void				iterate_loop_slash(char **pattern, int *nbs)
{
	(*nbs)++;
	(*pattern)++;
}

static t_dir_content	*loop_extend_candidat_slash(t_dir_content *list,
													int nbs,
													char *pattern)
{
	t_dir_content		*tmp;
	t_dir_content		*tmp2;
	int					current;

	tmp = list;
	current = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		current++;
	}
	tmp2 = list;
	while (current > -1)
	{
		if (tmp->next)
			tmp = tmp->next;
		tmp->next = get_dir_content(tmp2->name, nbs, *pattern == '.' ? 1 : 0);
		while (tmp->next)
			tmp = tmp->next;
		tmp2 = tmp2->next;
		current--;
	}
	return (list);
}

static t_dir_content	*extend_directories_slash(t_dir_content *list,
												char *pattern)
{
	struct stat			stat_buf;
	t_dir_content		*breakpoint;
	t_dir_content		*tmp;

	if (!list)
		return (list);
	breakpoint = list;
	tmp = list;
	while (breakpoint->next)
		breakpoint = breakpoint->next;
	while (tmp != breakpoint)
	{
		if (stat(tmp->name, &stat_buf) >= 0 && S_ISDIR(stat_buf.st_mode))
		{
			if (tmp->name[0] != '.' || *pattern == '.')
				list = add_dir_content("/", list, tmp->name);
		}
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		if (stat(tmp->name, &stat_buf) >= 0 && S_ISDIR(stat_buf.st_mode))
		{
			if (tmp->name[0] != '.' || *pattern == '.')
				list = add_dir_content("/", list, tmp->name);
		}
	}
	return (list);
}

t_dir_content			*extend_candidat_slash(t_dir_content *list,
												char *pattern)
{
	char				*tmp_pattern;
	int					bslash;
	int					nbs;

	bslash = 0;
	tmp_pattern = pattern;
	while (*pattern == '/')
		pattern++;
	while (*pattern)
	{
		nbs = 0;
		if (*pattern == '/' && !bslash)
		{
			while (*pattern == '/')
				iterate_loop_slash(&pattern, &nbs);
			tmp_pattern = *pattern == '\0' ? tmp_pattern : pattern;
			if (*pattern != '\0')
				list = loop_extend_candidat_slash(list, nbs, tmp_pattern);
			else
				list = extend_directories_slash(list, tmp_pattern);
		}
		else if (*pattern == '\\' && !bslash)
			bslash = 1;
		else
			bslash = 0;
		if (*pattern != '\0')
			pattern++;
	}
	return (list);
}
