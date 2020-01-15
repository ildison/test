/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2020/01/15 09:10:12 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*skip_spaces(void)
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

void		check_number(char *s)
{
	char	*num_alph;
	char	*tmp;

	num_alph = ft_itoa(ft_atoi(s));
	tmp = num_alph;
	if (*num_alph == '-' && *s != '-')
		error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
	if (*num_alph == '-' || *num_alph == '0')
		++num_alph;
	if (*s == '-' || *s == '+')
		++s;
	if (!*s)
		error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
	while (*s && *s == '0')
		++s;
	if (!ft_strequ(s, num_alph))
		error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
	free(tmp);
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
