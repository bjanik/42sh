/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_glob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:52:12 by heynard           #+#    #+#             */
/*   Updated: 2018/03/07 16:32:37 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_glob.h"

static t_dir_content	*init_list_of_candidats(unsigned int i, char **extended)
{
	t_dir_content		*list;
	unsigned int		j;

	if (extended[i][0] == '/')
	{
		j = 1;
		while (extended[i][j] == '/' || extended[i][j] == '.')
			j++;
		list = get_dir_first_content("/", j - 1, extended[i][j] == '.' ? 1 : 0);
	}
	else
		list = get_dir_content(".", 0, extended[i][0] == '.' ? 1 : 0);
	list = extend_candidat_slash(list, extended[i]);
	return (list);
}

char					**ft_glob(char *str)
{
	char				**extended;
	char				**globbed;
	t_dir_content		*list;
	unsigned int		i;

	globbed = NULL;
	list = NULL;
	if ((extended = glob_bracket(str)) == NULL)
		return (NULL);
	i = 0;
	while (extended[i])
	{
		list = init_list_of_candidats(i, extended);
		globbed = ft_2dstrjoin(globbed, glob_extend(extended[i], list));
		free_dir_content(list);
		i++;
	}
	ft_free2dstr(extended);
	return (globbed);
}

int						main(int ac, char **av)
{
	unsigned int		i;
	char				**test;

	if (ac > 1)
		test = ft_glob(av[1]);
	else
	{
		ft_putendl_fd("I need an argument !", STDERR_FILENO);
		return (0);
	}
	if (test)
	{
		i = 0;
		while (test[i])
		{
			ft_putstr(test[i++]);
			if (test[i])
				ft_putchar(' ');
		}
	}
	ft_free2dstr(test);
	ft_putchar('\n');
	//while (1);
	return (0);
}
