/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2020/01/13 13:38:04 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*skip_spaces()
{
	ASM_EOL = NULL;
	while (ft_isspace(*ASM_DATA))
	{
		if (*ASM_DATA == '\n' && !ASM_EOL)
			ASM_EOL = ASM_DATA;
		++ASM_DATA;
	}
	return (ASM_EOL);
}

static void	cpy_name_or_header(char **name_or_comment, int len)
{
	int		i;

	*name_or_comment = (char *)ft_memalloc(len);
	if (!*name_or_comment)
		error(strerror(errno));
	if (skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER);
	if (*ASM_DATA != '"')
		error_manager(ASM_ERR_WRONG_TITLE, ASM_NOT_OPER);
	else
		++ASM_DATA;
	i = 0;
	while (*ASM_DATA && *ASM_DATA != '"' && i < len)
	{
		*(*name_or_comment + i) = *ASM_DATA;
		++i;
		++ASM_DATA;
	}
	if (*ASM_DATA != '"')
		while (*ASM_DATA && *ASM_DATA != '"')
			++ASM_DATA;
	if (!*ASM_DATA)
		error_manager(ASM_ERR_WRONG_TITLE, ASM_NOT_OPER);
}

static void	pars_header(t_champ *champ)
{
	if (champ->prog_name && champ->comment)
		return ;
	if (!skip_spaces() && (champ->prog_name || champ->comment))
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER);
	if (ft_strnequ(ASM_DATA, NAME_CMD_STRING,\
	ft_strlen(NAME_CMD_STRING)) && !champ->prog_name)
	{
		ASM_DATA += ft_strlen(NAME_CMD_STRING);
		cpy_name_or_header(&champ->prog_name, PROG_NAME_LENGTH);
	}
	else if (ft_strnequ(ASM_DATA, COMMENT_CMD_STRING,\
	ft_strlen(COMMENT_CMD_STRING)) && !champ->comment)
	{
		ASM_DATA += ft_strlen(COMMENT_CMD_STRING);
		cpy_name_or_header(&champ->comment, COMMENT_LENGTH);
	}
	else
		error_manager(ASM_ERR_WRONG_TITLE, ASM_NOT_OPER);
	++ASM_DATA;
	pars_header(champ);
}

int			is_operation(char *data)
{
	int		i;
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



// int			is_label(char *data)
// {
	
// }

// void		

char		*get_arg()
{
	char	*arg;
	int		len;

	len = 0;
	while (ASM_DATA[len] && !ft_isspace(ASM_DATA[len]) &&\
							ASM_DATA[len] != SEPARATOR_CHAR)
		++len;
	arg = ft_strnew(len);
	if (!arg)
		error(strerror(errno));
	ft_strncpy(arg, ASM_DATA, len);
	ASM_DATA += len;
	return (arg);
}

void		check_label(char *label)
{
	if (!*label)
		error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER);
	while (*label)
	{
		if (!ft_strchr(LABEL_CHARS, *label))
			error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER);
		++label;
	}
}

void		check_number(char *s)
{
	char    *num_alph;
	char    *tmp;

	num_alph = ft_itoa(ft_atoi(s));
	tmp = num_alph;
	if (*num_alph == '-' && *s != '-')
	        error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER);
	if (*num_alph == '-' || *num_alph == '0')
	        ++num_alph;
	if (*s == '-' || *s == '+')
	        ++s;
	if (!*s)
	        error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER);
	while (*s && *s == '0')
	        ++s;
	if (!ft_strequ(s, num_alph))
	        error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER);
	free(tmp);
}

void		validation_arg(char *arg)
{
	if (*arg == 'r')
	{
		check_number(arg + 1);
		if (ft_atoi(arg + 1) == 0)
			error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER);
		return ;
	}
	if (*arg == DIRECT_CHAR)
		++arg;
	if (*arg == LABEL_CHAR)
		check_label(arg + 1);
	else
		check_number(arg);
}

unsigned char		set_arg_type(char *arg, int code)
{
	unsigned char	type;

	type = 0;
	if (*arg == DIRECT_CHAR)
		type = DIR_CODE;
	else if (*arg == 'r')
		type = REG_CODE;
	else if (ft_isdigit((int)*arg) || *arg == LABEL_CHAR)
		type = IND_CODE;
	else
		error_manager(ASM_ERR_WRONG_TYPE, code);
	return (type);
}

void		pars_args(t_oper *oper)
{
	int		n_arg;

	n_arg = 0;
	while (n_arg < op_tab[oper->code].args_num)
	{
		if (skip_spaces())
			error_manager(ASM_ERR_INVALID_PARAM, oper->code);
		oper->args[n_arg] = get_arg();
		oper->args_types[n_arg] = set_arg_type(oper->args[n_arg], oper->code);
		validation_arg(oper->args[n_arg]);
		++n_arg;
		if (n_arg < op_tab[oper->code].args_num)
		{
			if (skip_spaces())
				error_manager(ASM_ERR_INVALID_PARAM, oper->code);
			if (*ASM_DATA == SEPARATOR_CHAR)
				++ASM_DATA;
			else
				error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER);
		}
	}
	if (!skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER);
}

t_oper		*new_oper(int oper_code)
{
	t_oper	*oper;

	oper = (t_oper *)ft_memalloc(sizeof(t_oper));
	if (!oper)
		error(strerror(errno));
	oper->code = oper_code;
	return (oper);
}

void		add_new_oper(t_champ *champ, t_oper *oper)
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

void			validation_args_types(t_oper *oper)
{
	int			n_arg;

	n_arg = 0;
	while (n_arg < op_tab[oper->code].args_num)
	{
		if (!(oper->args_types[n_arg] & op_tab[oper->code].args_types[n_arg]))
			error_manager(ASM_ERR_WRONG_TYPE, oper->code);
		++n_arg;
	}
}

void		pars_opers(t_champ *champ)
{
	t_oper	*oper;
	int		oper_code;

	while (*ASM_DATA)
	{
		if ((oper_code = is_operation(ASM_DATA)))
		{
			oper = new_oper(oper_code);
			pars_args(oper);
			validation_args_types(oper);
			add_new_oper(champ, oper);
		}
		// skip_spaces();
	}
}

void		parsing_champ(t_champ *champ)
{
	pars_header(champ);
	if (!skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER);
	pars_opers(champ);
}
