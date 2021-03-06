/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_grammar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:12:51 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/06 14:44:20 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_GRAMMAR_H
# define SHELL_GRAMMAR_H

# include <stddef.h>
# include "parser_defs.h"
# include "s_container.h"
# include "ast_generation.h"

static char const	g_shell_grammar[] =
"PROGRAM"
":COMPLETE_COMMAND NEWLINE"
"|NEWLINE"
";"
"COMPLETE_COMMAND"
":LIST"
";"
"LIST"
":LIST SEPARATOR_OP AND_OR"
"|AND_OR"
";"
"AND_OR"
":PIPELINE"
"|AND_OR AND_IF PIPELINE"
"|AND_OR OR_IF PIPELINE"
";"
"PIPELINE"
":PIPELINE_PREOP PIPE_SEQUENCE"
";"
"PIPELINE_PREOP"
":BANG"
"|"
";"
"PIPE_SEQUENCE"
":PIPE_SEQUENCE PIPE SIMPLE_COMMAND"
"|SIMPLE_COMMAND"
";"
"SIMPLE_COMMAND"
":SIMPLE_COMMAND IO_REDIRECT"
"|SIMPLE_COMMAND WORD"
"|IO_REDIRECT"
"|WORD"
";"
"IO_REDIRECT"
":IO_NUMBER IO_OPERATOR WORD"
"|IO_OPERATOR WORD"
";"
"IO_OPERATOR"
":LESS"
"|LESSAND"
"|GREAT"
"|DGREAT"
"|GREATAND"
"|LESSGREAT"
"|DLESS"
"|DLESSDASH"
"|CLOBBER"
";"
"SEPARATOR_OP"
":SEMICOLON"
";";

static char const	*g_tokens_name[] = {
	"WORD",
	"NEWLINE",
	"IO_NUMBER",
	"DLESS",
	"DGREAT",
	"LESSAND",
	"GREATAND",
	"LESS",
	"GREAT",
	"AND_IF",
	"OR_IF",
	"SEMICOLON",
	"PIPE",
	"CLOBBER",
	"LESSGREAT",
	"DLESSDASH",
	"BANG",
	NULL
};

static t_exec const	g_exec_rules[] = {
	{ .name="PROGRAM",
		.create=&create_program,
		.give=&give_program,
		.destroy=&destroy_program
	}, { .name="COMPLETE_COMMAND",
		.create=&create_complete_command,
		.give=&give_complete_command,
		.destroy=&destroy_container
	}, { .name="LIST",
		.create=&create_sh_list,
		.give=&give_sh_list,
		.destroy=&destroy_container
	}, { .name="AND_OR",
		.create=&create_and_or,
		.give=&give_and_or,
		.destroy=&destroy_container
	}, { .name="PIPELINE_PREOP",
		.create=&create_pipeline_preop,
		.give=&give_pipeline_preop,
		.destroy=&destroy_container
	}, { .name="PIPELINE",
		.create=&create_pipeline,
		.give=&give_pipeline,
		.destroy=&destroy_container
	}, { .name="PIPE_SEQUENCE",
		.create=&create_pipe_sequence,
		.give=&give_pipe_sequence,
		.destroy=&destroy_container
	}, { .name="SIMPLE_COMMAND",
		.create=&create_simple_command,
		.give=&give_simple_command,
		.destroy=&destroy_container
	}, { .name="IO_REDIRECT",
		.create=&create_io_redirect,
		.give=&give_io_redirect,
		.destroy=&destroy_container
	}, { .name="IO_OPERATOR",
		.create=&create_io_operator,
		.give=&give_io_operator,
		.destroy=&destroy_container
	}, { .name="WORD",
		.create=&create_word,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="AND_IF",
		.create=&create_and_if,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="OR_IF",
		.create=&create_or_if,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="IO_NUMBER",
		.create=&create_io_number,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="LESS",
		.create=&create_less,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="DLESS",
		.create=&create_dless,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="DLESSDASH",
		.create=&create_dlessdash,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="LESSAND",
		.create=&create_lessand,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="LESSGREAT",
		.create=&create_lessgreat,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="GREAT",
		.create=&create_great,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="DGREAT",
		.create=&create_dgreat,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="GREATAND",
		.create=&create_greatand,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="CLOBBER",
		.create=&create_clobber,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name="BANG",
		.create=&create_bang,
		.give=NULL,
		.destroy=&destroy_container
	}, { .name=NULL, .create=NULL, .give=NULL, .destroy=NULL }
};

#endif
