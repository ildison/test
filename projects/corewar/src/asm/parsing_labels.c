/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:40:03 by cormund           #+#    #+#             */
/*   Updated: 2020/01/14 09:20:53 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_label(char *data)
{
	int		len;

	len = 0;
	if (*data == LABEL_CHAR)
		error_manager(ASM_ERR_WRONG_LABEL, ASM_NOT_OPER);
	while (data[len] && !ft_isspace(data[len]))
	{
		if (data[len] == LABEL_CHAR)
			return (len);
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
