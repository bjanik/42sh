/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_compute_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:19:37 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/02 17:59:47 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"

static t_bool	prod_add_to_first(void *prod, va_list args)
{
	t_symbol	*sym_add_to;
	t_bool		*sym_added;

	sym_add_to = va_arg(args, t_symbol*);
	sym_added = va_arg(args, t_bool*);
	return (add_firsts_of_sub_symbols(prod, sym_add_to, sym_added));
}

t_bool			compute_sym_first_set(t_symbol *sym, t_bool *sym_added)
{
	t_bool	error_state;

	if (sym->prods == NULL && f_lst_len(sym->first) == 0)
	{
		error_state = NULL != f_lstpush(sym, &sym->first);
		*sym_added = TRUE;
	}
	else
	{
		if (has_empty_prod(sym))
			error_state = add_symbol_to_first_set(EMPTY_SYMBOL, sym, sym_added);
		error_state = f_lstiterr_va(sym->prods,
				prod_add_to_first, sym, sym_added);
	}
	return (error_state);
}

t_bool			add_first_set_to_first_set(
		t_symbol const *sym,
		t_symbol *add_to,
		t_bool *sym_added)
{
	return (add_first_set_to_set(sym, &add_to->first, sym_added));
}

t_bool			add_symbol_to_set(
		t_symbol const *sym,
		t_lst **set,
		t_bool *sym_added)
{
	if (!has_symbol_in_set(*set, sym))
	{
		*sym_added = TRUE;
		return (NULL != f_lstpush(sym, set));
	}
	else
		return (TRUE);
}
