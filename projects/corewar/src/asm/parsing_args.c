/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:31:50 by cormund           #+#    #+#             */
/*   Updated: 2020/02/13 12:03:23 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void				validation_arg(char *arg)
{
	if (*arg == 'r')
	{
		check_number(arg + 1);
		if (ft_atoi(arg + 1) <= 0 || ft_atoi(arg + 1) > 16)
			error_manager(ASM_ERR_REG_VALUE, ASM_NOT_OPER, ASM_NOT_LABEL);
		return ;
	}
	if (*arg == DIRECT_CHAR)
		++arg;
	if (*arg == LABEL_CHAR)
		check_label(arg + 1);
	else
		check_number(arg);
}

static char				*get_arg(void)
{
	char				*arg;
	int					len;

	len = 0;
	while (g_data.data[len] && !ft_isspace(g_data.data[len]) &&\
							g_data.data[len] != SEPARATOR_CHAR)
		++len;
	arg = ft_strnew(len);
	if (!arg)
		ERROR(strerror(errno));
	ft_strncpy(arg, g_data.data, len);
	validation_arg(arg);
	g_data.data += len;
	return (arg);
}

void					validation_args_types(t_oper *oper)
{
	int					n_arg;

	n_arg = 0;
	while (n_arg < oper->op->args_num)
	{
		if (!(oper->args_types[n_arg] & oper->op->args_types[n_arg]))
			error_manager(ASM_ERR_WRONG_TYPE, oper->op, ASM_NOT_LABEL);
		++n_arg;
	}
}

static unsigned char	set_arg_type(char *arg, t_op *op)
{
	unsigned char		type;

	type = 0;
	if (*arg == '-' || *arg == '+')
		++arg;
	if (*arg == DIRECT_CHAR)
		type = T_DIR;
	else if (*arg == 'r')
		type = T_REG;
	else if (ft_isdigit((int)*arg) || *arg == LABEL_CHAR)
		type = T_IND;
	else
		error_manager(ASM_ERR_WRONG_TYPE, op, ASM_NOT_LABEL);
	return (type);
}

void					pars_args(t_oper *oper)
{
	int					n_arg;

	n_arg = 0;
	while (n_arg < oper->op->args_num)
	{
		if (skip_spaces())
			error_manager(ASM_ERR_INVALID_PARAM, oper->op, ASM_NOT_LABEL);
		oper->args[n_arg] = get_arg();
		oper->args_types[n_arg] = set_arg_type(oper->args[n_arg],\
												oper->op);
		++n_arg;
		if (n_arg < oper->op->args_num)
		{
			if (skip_spaces())
				error_manager(ASM_ERR_INVALID_PARAM, oper->op, ASM_NOT_LABEL);
			if (*g_data.data == SEPARATOR_CHAR)
				++g_data.data;
			else
				error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
		}
	}
	if (!skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER, ASM_NOT_LABEL);
}
