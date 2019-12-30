/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2019/12/30 15:18:51 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*skip_spaces()
{
	char	*ptr_end_of_str;

	ptr_end_of_str = NULL;
	while (ft_isspace(*ASM_DATA))
	{
		if (*ASM_DATA == '\n' && !ptr_end_of_str)
			ptr_end_of_str = ASM_DATA;
		++ASM_DATA;
	}
	return (ptr_end_of_str);
}

static char	*cpy_name_or_header(char **name_or_comment, int len)
{
	int		i;

	*name_or_comment = (char *)ft_memalloc(len);
	if (!*name_or_comment)
		error(strerror(errno));
	skip_spaces();
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
	return (++ASM_DATA);
}

static void	pars_header(t_champ *champ)
{
	if (champ->prog_name && champ->comment)
		return ;
	skip_spaces();
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
	pars_header(champ);
}

// int			is_operation(char *data)
// {
	
// }

// int			is_label(char *data)
// {
	
// }

// void		pars_opers(t_champ *champ, char *data)
// {
// 	skip_spaces(&data);
// 	while (*data)
// 	{
// 		if ()
// 		skip_spaces(&data);
// 	}
// }

void		parsing_champ(t_champ *champ)
{
	pars_header(champ);
	// data = pars_opers(champ, data);
}
