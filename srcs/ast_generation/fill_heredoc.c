/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:12:03 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/02 18:12:04 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "bleberr_macros.h"
#include "io_here.h"
#include "shell.h"
#include <sys/ioctl.h>
#include <signal.h>

static void		remove_leading_tabs(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] == '\t')
			i += 1;
		if (i)
			ft_memmove(str, str + i, ft_strlen(str + i) + 1);
	}
}

static void		init_prompt(t_term *term, char const *prompt)
{
	struct winsize	ws;

	if (prompt)
	{
		ft_strncpy(term->prompt, prompt, MAX_PROMPT_SIZE);
		term->prompt[MAX_PROMPT_SIZE] = 0;
		term->prompt_len = ft_strlen(term->prompt);
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		term->width = ws.ws_col;
		term->first_line_len = term->width - term->prompt_len;
	}
}

static char		*get_heredoc_line(t_bool is_dlessdash)
{
	t_bsh	*const bsh = get_shell_data();

	if (bsh)
	{
		init_prompt(bsh->input.term, "heredoc> ");
		ft_dprintf(2, "%s", bsh->input.term->prompt);
		ft_memset(bsh->input.buffer, 0, bsh->input.buffer_size);
		bsh->input.buffer_len = 0;
		if (!getline(&bsh->input, bsh->interactive, HEREDOC_INPUT,
					&bsh->lexer.state))
		{
			if (is_dlessdash)
				remove_leading_tabs(bsh->input.buffer);
			return (bsh->input.buffer);
		}
	}
	return (NULL);
}

int				fill_heredoc(int const doc_fd, char const *const here_end,
		size_t const here_end_len, t_bool is_dlessdash)
{
	char	*line;

	line = NULL;
	while (42)
	{
		if ((line = get_heredoc_line(is_dlessdash)))
		{
			if (ft_strlen(line) && ft_strncmp(line, here_end, here_end_len))
				(void)ft_dprintf(doc_fd, "%s", line);
			else
				break ;
		}
		else
			return (42);
	}
	return (0);
}