/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:14:13 by cormund           #+#    #+#             */
/*   Updated: 2020/02/10 16:01:54 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	clean_opers(t_oper *oper)
{
	int		n_arg;

	if (!oper)
		return ;
	clean_opers(oper->next);
	n_arg = 0;
	while (n_arg < oper->op->args_num)
	{
		free(oper->args[n_arg]);
		++n_arg;
	}
	free(oper);
}

static void	clean_labels(t_label *label)
{
	if (!label)
		return ;
	clean_labels(label->next);
	free(label->name);
	free(label);
}

void		clean_up(t_champ *champ)
{
	free(champ->file_name);
	free(champ->prog_name);
	free(champ->comment);
	clean_opers(champ->first_oper);
	clean_labels(champ->label);
	ft_bzero(champ, sizeof(t_champ));
	free(g_data.input);
	ft_bzero(&g_data, sizeof(t_data));
}
