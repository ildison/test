/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_oper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:53:02 by cormund           #+#    #+#             */
/*   Updated: 2020/02/13 12:12:19 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_op		*is_operation(char *data)
{
	int			i;

	i = 15;
	while (i >= 0)
	{
		if (ft_strnequ(g_op_tab[i].name, data, ft_strlen(g_op_tab[i].name)))
		{
			g_data.data += ft_strlen(g_op_tab[i].name);
			return (&g_op_tab[i]);
		}
		--i;
	}
	g_data.eol = NULL;
	return (0);
}

static t_oper	*new_oper(t_op *op)
{
	t_oper		*oper;

	oper = (t_oper *)ft_memalloc(sizeof(t_oper));
	if (!oper)
		ERROR(strerror(errno));
	oper->op = op;
	return (oper);
}

static void		add_new_oper(t_champ *champ, t_oper *oper)
{
	if (!champ->first_oper)
		champ->first_oper = oper;
	else
		champ->last_oper->next = oper;
	champ->last_oper = oper;
}

static void		set_size_oper(t_oper *oper)
{
	int			n_arg;

	oper->size = 1;
	oper->size += oper->op->need_types ? 1 : 0;
	n_arg = 0;
	while (n_arg < oper->op->args_num)
	{
		if (oper->args_types[n_arg] == T_REG)
			oper->size += 1;
		else if (oper->args_types[n_arg] == T_IND)
			oper->size += 2;
		else
			oper->size += oper->op->dir_size ? 2 : 4;
		++n_arg;
	}
}

void			pars_opers(t_champ *champ)
{
	t_op		*op;
	t_oper		*oper;
	t_label		*label;
	int			len_label;

	while (*g_data.data)
		if ((len_label = is_label(g_data.data)))
		{
			label = new_label(len_label);
			label->offset = set_offset(champ);
			add_new_label(champ, label);
			g_data.data += len_label + 1;
			skip_spaces();
		}
		else if ((op = is_operation(g_data.data)))
		{
			oper = new_oper(op);
			pars_args(oper);
			validation_args_types(oper);
			set_size_oper(oper);
			oper->offset = set_offset(champ);
			add_new_oper(champ, oper);
		}
		else
			error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
}
