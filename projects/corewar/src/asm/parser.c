/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2020/01/10 15:43:16 by cormund          ###   ########.fr       */
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

char		**take_args(unsigned char code)
{
	char	**args;
	int		n_arg;

	if (!(args = (char **)malloc(sizeof(char *) * op_tab[code].args_num)))
		error(strerror(errno));
	n_arg = 0;
	while (n_arg < op_tab[code].args_num)
	{
		if (skip_spaces())
			error_manager(ASM_ERR_INVALID_PARAM, code);
		args[n_arg] = get_arg();
		++n_arg;
		if (n_arg < op_tab[code].args_num)
		{
			if (skip_spaces())
				error_manager(ASM_ERR_INVALID_PARAM, code);
			if (*ASM_DATA == SEPARATOR_CHAR)
				++ASM_DATA;
			else
				error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER);
		}
	}
	if (!skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER);
	return (args);
}

void		pars_opers()
{
	int		oper_code;
	char	**args;

	while (*ASM_DATA)
	{
		if ((oper_code = is_operation(ASM_DATA)))
		{
			args = take_args(oper_code);
			// add_new_oper(champ, oper_code);
			printf("Yes\n");
		}
		skip_spaces();
		// ++ASM_DATA;
	}
}

void		parsing_champ(t_champ *champ)
{
	pars_header(champ);
	if (!skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER);
	pars_opers();
}
