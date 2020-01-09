/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2020/01/09 18:30:04 by cormund          ###   ########.fr       */
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
		error_manager("Syntax error: ENDLINE");
	if (*ASM_DATA != '"')
		error_manager("Syntax error: wrong title");
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
		error_manager("Syntax error: wrong title");
}

static void	pars_header(t_champ *champ)
{
	if (champ->prog_name && champ->comment)
		return ;
	if (!skip_spaces() && (champ->prog_name || champ->comment))
		error_manager("Syntax error: ENDLINE");
		printf("<%s>\n", ft_strndup(ASM_DATA, 1));
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
		error_manager("Syntax error: wrong title");
	++ASM_DATA;
	pars_header(champ);
}

int			is_operation(char *data)
{
	int		i;
	char	*opers[17] = {"", "live", "ld", "st", "add", "sub", "and", "or", "xor",\
			"zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};

	i = 16;
	while (i > 0)
	{
		if (ft_strnequ(opers[i], data, ft_strlen(opers[i])))
		{
			ASM_DATA += ft_strlen(opers[i]);
			return (i);
		}
		--i;
	}
	return (0);
}



int			is_label(char *data)
{
	
}

void		

char		*get_arg()
{
	char	*arg;
	int		len;

	len = 0;
	while (ASM_DATA[len] && ASM_DATA[len] != ' ' && ASM_DATA[len] != '\n'\
			&& ASM_DATA[len] != SEPARATOR_CHAR)
		++len;
	arg = ft_strnew(len);
	if (!arg)
		error(strerror(errno));
	ft_strncpy(arg, ASM_DATA, len);
	ASM_DATA += len;
	return (arg);
}

t_arg		take_args()
{
	t_arg	new_args;

	ft_bzero(&new_args, sizeof(t_arg));
	if (skip_spaces())
		error_manager("Syntax error: ENDLINE");
	new_args.first = get_arg();
	skip_spaces();
	if (*ASM_DATA == SEPARATOR_CHAR && ASM_EOL)
		error_manager("Syntax error: ENDLINE");
	
	
}

void		pars_opers(t_champ *champ)
{
	int		oper_code;
	t_arg	args;

	while (*ASM_DATA)
	{
		if ((oper_code = is_operation(ASM_DATA)))
		{
			args = take_args();
			add_new_oper(champ, oper_code);
			
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
		error_manager("Syntax error: ENDLINE");
	pars_opers(champ);
}
