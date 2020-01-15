/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:28:36 by cormund           #+#    #+#             */
/*   Updated: 2020/01/15 16:09:32 by cormund          ###   ########.fr       */
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

void	error_manager(char *error, unsigned char oper_code, char *wrong_label)
{
	int	ln;
	int	col;

	if (oper_code)
		ft_printf("%s %s\n", error, g_op_tab[oper_code].name);
	else if (wrong_label)
		ft_printf("%s: %s\n", error, wrong_label);
	else
	{
		check_ln_col(&ln, &col, ASM_INPUT, ASM_EOL ? ASM_EOL : ASM_DATA);
		ft_printf("%s [%d:%d]\n", error, ln, col);
	}
	exit(-1);
}
