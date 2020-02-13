/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:28:36 by cormund           #+#    #+#             */
/*   Updated: 2020/02/13 12:01:16 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_ln_col(int *ln, int *col, char *data, char *ptr_error)
{
	*ln = 1;
	*col = 0;
	while (*data)
	{
		*col += *data != '\t' ? 1 : 4;
		if (data == ptr_error)
			break ;
		if (*data == '\n')
		{
			++*ln;
			*col = 0;
		}
		++data;
	}
}

void	error_manager(char *error, t_op *wrong_oper, char *wrong_label)
{
	int	ln;
	int	col;

	if (wrong_oper)
		ft_printf("%s %s\n", error, wrong_oper->name);
	else if (wrong_label)
		ft_printf("%s: %s\n", error, wrong_label);
	else
	{
		check_ln_col(&ln, &col, g_data.input, g_data.eol ?\
								g_data.eol : g_data.data);
		ft_printf("%s [%d:%d]\n", error, ln, col);
	}
	exit(-1);
}
