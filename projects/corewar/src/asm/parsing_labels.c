/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:40:03 by cormund           #+#    #+#             */
/*   Updated: 2020/01/15 13:20:22 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_label(char *label)
{
	if (!*label)
		error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
	while (*label && *label != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, *label))
			error_manager(ASM_ERR_LEXICAL, ASM_NOT_OPER, ASM_NOT_LABEL);
		++label;
	}
}

int			is_label(char *data)
{
	int		len;

	len = 0;
	if (*data == LABEL_CHAR)
		error_manager(ASM_ERR_WRONG_LABEL, ASM_NOT_OPER, ASM_NOT_LABEL);
	while (data[len] && !ft_isspace(data[len]) && data[len] != DIRECT_CHAR)
	{
		if (data[len] == LABEL_CHAR)
		{
			if (!ASM_EOL)
				error_manager(ASM_ERR_WRONG_LABEL, ASM_NOT_OPER, ASM_NOT_LABEL);
			check_label(ASM_DATA);
			return (len);
		}
		++len;
	}
	return (0);
}

t_label		*new_label(int len_label)
{
	t_label	*new;

	new = ft_memalloc(sizeof(t_label));
	if (!new)
		error(strerror(errno));
	new->name = ft_strndup(ASM_DATA, len_label);
	if (!new->name)
		error(strerror(errno));
	return (new);
}

void		add_new_label(t_champ *champ, t_label *label)
{
	if (!champ->label)
		champ->label = label;
	else
	{
		label->next = champ->label;
		champ->label = label;
	}
}
