/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:31:50 by cormund           #+#    #+#             */
/*   Updated: 2020/01/17 12:41:10 by cormund          ###   ########.fr       */
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
	while (ASM_DATA[len] && !ft_isspace(ASM_DATA[len]) &&\
							ASM_DATA[len] != SEPARATOR_CHAR)
		++len;
	arg = ft_strnew(len);
	if (!arg)
		error(strerror(errno));
	ft_strncpy(arg, ASM_DATA, len);
	validation_arg(arg);
	ASM_DATA += len;
	return (arg);
}

void					validation_args_types(t_oper *oper)
{
	int					n_arg;

	n_arg = 0;
	while (n_arg < oper->op->args_num)
	{
		if (!(oper->args_types[n_arg] & oper->op->args_types[n_arg]))
			error_manager(ASM_ERR_WRONG_TYPE, oper->op->code, ASM_NOT_LABEL);
		++n_arg;
	}
}

static unsigned char	set_arg_type(char *arg, int code)
{
	unsigned char		type;

	type = 0;
	if (*arg == '-' || *arg == '+')
		++arg;
	if (*arg == DIRECT_CHAR)
		type = DIR_CODE;
	else if (*arg == 'r')
		type = REG_CODE;
	else if (ft_isdigit((int)*arg) || *arg == LABEL_CHAR)
		type = IND_CODE;
	else
		error_manager(ASM_ERR_WRONG_TYPE, code, ASM_NOT_LABEL);
	return (type);
}

void					pars_args(t_oper *oper)
{
	int					n_arg;

	n_arg = 0;
	while (n_arg < oper->op->args_num)
	{
		if (skip_spaces())
			error_manager(ASM_ERR_INVALID_PARAM, oper->op->code, ASM_NOT_LABEL);
		oper->args[n_arg] = get_arg();
		oper->args_types[n_arg] = set_arg_type(oper->args[n_arg],\
												oper->op->code);
		++n_arg;
		if (n_arg < oper->op->args_num)
		{
			if (skip_spaces())
				error_manager(ASM_ERR_INVALID_PARAM, oper->op->code,\
														ASM_NOT_LABEL);
			if (*ASM_DATA == SEPARATOR_CHAR)
				++ASM_DATA;
			else
				error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
		}
	}
	if (!skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER, ASM_NOT_LABEL);
}
