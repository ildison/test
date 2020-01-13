/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_oper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:53:02 by cormund           #+#    #+#             */
/*   Updated: 2020/01/13 17:31:32 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		is_operation(char *data)
{
	int			i;
	// char	*opers[17] = {"", "live", "ld", "st", "add", "sub", "and", "or", "xor",\
	// 		"zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};

	i = 16;
	while (i > 0)
	{
		if (ft_strnequ(op_tab[i].name, data, ft_strlen(op_tab[i].name)))
		{
			ASM_DATA += ft_strlen(op_tab[i].name);
			return (i);
		}
		--i;
	}
	return (0);
}

static t_oper	*new_oper(int oper_code)
{
	t_oper		*oper;

	oper = (t_oper *)ft_memalloc(sizeof(t_oper));
	if (!oper)
		error(strerror(errno));
	oper->code = oper_code;
	return (oper);
}

static void		add_new_oper(t_champ *champ, t_oper *oper)
{
	if (!champ->first_oper)
	{
		champ->first_oper = oper;
		champ->last_oper = oper;
	}
	else
	{
		oper->prev = champ->last_oper;
		champ->last_oper->next = oper;
		champ->last_oper = oper;
	}
}

static void		set_size_oper(t_oper *oper)
{
	int			n_arg;

	oper->size = 1;
	oper->size += op_tab[oper->code].need_types ? 1 : 0;
	n_arg = 0;
	while (n_arg < op_tab[oper->code].args_num)
	{
		if (oper->args_types[n_arg] == REG_CODE)
			oper->size += 1;
		else if (oper->args_types[n_arg] == IND_CODE)
			oper->size += 1;
		else
			oper->size += op_tab[oper->code].dir_size ? 2 : 4;
		++n_arg;
	}
}

void			pars_opers(t_champ *champ)
{
	t_oper		*oper;
	int			len_label;
	int			oper_code;

	while (*ASM_DATA)
	{
		if ((len_label = is_label(ASM_DATA)))
		{
			if (!ASM_EOL)
				error_manager(ASM_ERR_WRONG_LABEL, ASM_NOT_OPER);
			check_label(ASM_DATA);
		}
		else if ((oper_code = is_operation(ASM_DATA)))
		{
			oper = new_oper(oper_code);
			pars_args(oper);
			validation_args_types(oper);
			set_size_oper(oper);
			oper->offset = set_offset(champ);
			add_new_oper(champ, oper);
		}
		// skip_spaces();
	}
}
