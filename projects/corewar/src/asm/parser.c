/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2019/12/27 16:26:42 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		skip_spaces(char **data)
{
	while (ft_isspace(**data))
		++*data;
}

static char	*cpy_name_or_header(t_champ *champ, char **name_or_comment, char *data, int len)
{
	int		i;

	*name_or_comment = (char *)ft_memalloc(len);
	if (!*name_or_comment)
		error(strerror(errno));
	skip_spaces(&data);
	if (*data != '"')
		error_manager("Syntax error: wrong title", champ->data, data);
	else
		++data;
	i = 0;
	while (*data && *data != '"' && i < len)
	{
		*(*name_or_comment + i) = *data;
		++i;
		++data;
	}
	if (*data != '"')
		while (*data && *data != '"')
			++data;
	if (!*data)
		error_manager("Syntax error: wrong title", champ->data, data);
	return (++data);
}

static char	*pars_header(t_champ *champ, char *data)
{
	if (champ->prog_name && champ->comment)
		return (data);
	skip_spaces(&data);
	if (ft_strnequ(data, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) &&\
														!champ->prog_name)
		data = cpy_name_or_header(champ, &champ->prog_name, data +\
							ft_strlen(NAME_CMD_STRING), PROG_NAME_LENGTH);
	else if (ft_strnequ(data, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))
															&& !champ->comment)
		data = cpy_name_or_header(champ, &champ->comment, data +\
					ft_strlen(COMMENT_CMD_STRING), COMMENT_LENGTH);
	else
		error_manager("Syntax error: wrong title", champ->data, data);
	return (pars_header(champ, data));
}

int			is_operation(char *data)
{
	
}

int			is_label(char *data)
{
	
}

void		pars_opers(t_champ *champ, char *data)
{
	skip_spaces(&data);
	while (*data)
	{
		if ()
		skip_spaces(&data);
	}
}

void		parsing_champ(t_champ *champ, char *data)
{
	data = pars_header(champ, data);
	// data = pars_opers(champ, data);
}
