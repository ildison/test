/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:10:51 by cormund           #+#    #+#             */
/*   Updated: 2020/01/15 15:18:24 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	cpy_name_or_header(char **name_or_comment, int len)
{
	int		i;

	*name_or_comment = (char *)ft_memalloc(len + 4);
	if (!*name_or_comment)
		error(strerror(errno));
	if (skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER, ASM_NOT_LABEL);
	if (*ASM_DATA != '"')
		error_manager(ASM_ERR_WRONG_TITLE, ASM_NOT_OPER, ASM_NOT_LABEL);
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
		error_manager(ASM_ERR_WRONG_TITLE, ASM_NOT_OPER, ASM_NOT_LABEL);
}

void		pars_header(t_champ *champ)
{
	if (champ->prog_name && champ->comment)
		return ;
	if (!skip_spaces() && (champ->prog_name || champ->comment))
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER, ASM_NOT_LABEL);
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
		error_manager(ASM_ERR_WRONG_TITLE, ASM_NOT_OPER, ASM_NOT_LABEL);
	++ASM_DATA;
	pars_header(champ);
}
