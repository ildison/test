/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:59:25 by cormund           #+#    #+#             */
/*   Updated: 2019/12/24 18:14:44 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*cpy_name_or_header(t_champ *champ, char **name_or_comment, char *input, int len)
{
	int		i;

	*name_or_comment = (char *)ft_memalloc(len);
	if (!*name_or_comment)
		error(strerror(errno));
	while (ft_isspace(*input))
		++input;
	if (*input != '"')
		error_manager("Syntax error: wrong title", champ->input, input);
	else
		++input;
	i = 0;
	while (*input && *input != '"' && i < len)
	{
		*(*name_or_comment + i) = *input;
		++i;
		++input;
	}
	if (*input != '"')
		while (*input && *input != '"')
			++input;
	if (!*input)
		error_manager("Syntax error: wrong title", champ->input, input);
	return (++input);
}

static char	*pars_header(t_champ *champ, char *input)
{
	if (champ->prog_name && champ->comment)
		return (input);
	while (ft_isspace(*input))
		++input;
	if (ft_strnequ(input, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) && !champ->prog_name)
		input = cpy_name_or_header(champ, &champ->prog_name, input + ft_strlen(NAME_CMD_STRING), PROG_NAME_LENGTH);
	else if (ft_strnequ(input, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) && !champ->comment)
		input = cpy_name_or_header(champ, &champ->comment, input + ft_strlen(COMMENT_CMD_STRING), COMMENT_LENGTH);
	else
		error_manager("Syntax error: wrong title pars_header", champ->input, input);
	return (pars_header(champ, input));
}

void		parsing_champ(t_champ *champ, char *input)
{
	input = pars_header(champ, input);
}
