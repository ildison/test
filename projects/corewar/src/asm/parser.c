/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2020/01/13 16:00:26 by cormund          ###   ########.fr       */
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

// int			is_label(char *data)
// {
	
// }

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
		error_manager(ASM_ERR_ENDLINE, ASM_NOT_OPER);
	pars_opers(champ);
}
