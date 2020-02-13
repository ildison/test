/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:10:51 by cormund           #+#    #+#             */
/*   Updated: 2020/02/10 16:01:39 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	cpy_name_or_header(char **name_or_comment, int len)
{
	int		i;

	*name_or_comment = (char *)ft_memalloc(len + 4);
	if (!*name_or_comment)
		ERROR(strerror(errno));
	if (skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER, ASM_NOT_LABEL);
	if (*g_data.data != '"')
		error_manager(ASM_ERR_WRONG_TITLE, ASM_NOT_OPER, ASM_NOT_LABEL);
	else
		++g_data.data;
	i = 0;
	while (*g_data.data && *g_data.data != '"' && i < len)
	{
		*(*name_or_comment + i) = *g_data.data;
		++i;
		++g_data.data;
	}
	if (*g_data.data != '"')
		while (*g_data.data && *g_data.data != '"')
			++g_data.data;
	if (!*g_data.data)
		error_manager(ASM_ERR_WRONG_TITLE, ASM_NOT_OPER, ASM_NOT_LABEL);
}

void		pars_header(t_champ *champ)
{
	if (champ->prog_name && champ->comment)
		return ;
	if (!skip_spaces() && (champ->prog_name || champ->comment))
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER, ASM_NOT_LABEL);
	if (ft_strnequ(g_data.data, NAME_CMD_STRING,\
	ft_strlen(NAME_CMD_STRING)) && !champ->prog_name)
	{
		g_data.data += ft_strlen(NAME_CMD_STRING);
		cpy_name_or_header(&champ->prog_name, PROG_NAME_LENGTH);
	}
	else if (ft_strnequ(g_data.data, COMMENT_CMD_STRING,\
	ft_strlen(COMMENT_CMD_STRING)) && !champ->comment)
	{
		g_data.data += ft_strlen(COMMENT_CMD_STRING);
		cpy_name_or_header(&champ->comment, COMMENT_LENGTH);
	}
	else
		error_manager(ASM_ERR_WRONG_TITLE, ASM_NOT_OPER, ASM_NOT_LABEL);
	++g_data.data;
	pars_header(champ);
}
