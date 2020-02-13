/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:40:03 by cormund           #+#    #+#             */
/*   Updated: 2020/02/13 12:04:53 by cormund          ###   ########.fr       */
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
			if (!g_data.eol)
				error_manager(ASM_ERR_WRONG_LABEL, ASM_NOT_OPER, ASM_NOT_LABEL);
			g_data.eol = NULL;
			check_label(g_data.data);
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
		ERROR(strerror(errno));
	new->name = ft_strndup(g_data.data, len_label);
	if (!new->name)
		ERROR(strerror(errno));
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
