/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2020/01/13 15:33:02 by cormund          ###   ########.fr       */
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



void		set_size_oper(t_oper *oper)
{
	int		n_arg;

	oper->size = 1;
	oper->size += op_tab[oper->code].need_types ? 1 : 0;
	n_arg = 0;
	while (n_arg < op_tab[oper->code].args_num)
	{
		if (oper->args_types[n_arg] == REG_CODE)
			oper->size += 1;
		else if (oper->args_types[n_arg] == IND_CODE)
			oper->size += 1;
		else
			oper->size += op_tab[oper->code].dir_size ? 2 : 4;
		++n_arg;
	}
}

void		set_offset(t_champ *champ, t_oper *oper)
{
	if (!champ->last_oper)
		oper->offset = 0;
	else
		oper->offset = champ->last_oper->offset + champ->last_oper->size;
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
			set_size_oper(oper);
			// printf("size of %s - %d\n", op_tab[oper->code].name, oper->size);
			set_offset(champ, oper);
			// printf("offset = %d\n", oper->offset);
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
