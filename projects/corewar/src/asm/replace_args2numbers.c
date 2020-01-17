/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_args2numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:14:54 by cormund           #+#    #+#             */
/*   Updated: 2020/01/17 10:30:11 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	replace_label(t_champ *champ, char *srch_label, int oper_offset)
{
	t_label	*label;
	int		value;

	value = 0;
	label = champ->label;
	while (label && !ft_strequ(srch_label, label->name))
		label = label->next;
	if (label)
		value = label->offset - oper_offset;
	else
		error_manager(ASM_ERR_WRONG_LABEL, ASM_NOT_OPER, srch_label);
	return (value);
}

static void	replace_args(t_champ *champ, t_oper *oper)
{
	char	*arg;
	int		n_arg;

	n_arg = 0;
	while (n_arg < oper->op->args_num)
	{
		arg = oper->args[n_arg];
		if (oper->args_types[n_arg] == T_REG ||\
			oper->args_types[n_arg] == T_DIR)
			++arg;
		if (*arg == LABEL_CHAR)
			oper->nums[n_arg] = replace_label(champ, arg + 1, oper->offset);
		else
			oper->nums[n_arg] = ft_atoi(arg);
		++n_arg;
	}
}

void		replace_args2numbers(t_champ *champ)
{
	t_oper	*oper;

	oper = champ->first_oper;
	while (oper)
	{
		replace_args(champ, oper);
		oper = oper->next;
	}
}
