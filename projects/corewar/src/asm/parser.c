/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2020/02/10 16:02:10 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*skip_spaces(void)
{
	g_data.eol = NULL;
	while (ft_isspace(*g_data.data))
	{
		if (*g_data.data == '\n' && !g_data.eol)
			g_data.eol = g_data.data;
		++g_data.data;
	}
	return (g_data.eol);
}

void		check_number(char *s)
{
	if (*s == '-' || *s == '+')
		++s;
	if (!*s)
		error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
	while (*s && ft_isdigit(*s))
		++s;
	if (*s)
		error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
}

int			set_offset(t_champ *champ)
{
	if (!champ->last_oper)
		return (0);
	else
		return (champ->last_oper->offset + champ->last_oper->size);
}

void		parsing_champ(t_champ *champ)
{
	pars_header(champ);
	if (!skip_spaces())
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER, ASM_NOT_LABEL);
	pars_opers(champ);
	if (!champ->first_oper)
		error_manager(ASM_ERR_END, ASM_NOT_OPER, ASM_NOT_LABEL);
	replace_args2numbers(champ);
}
