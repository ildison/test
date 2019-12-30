/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:28:36 by cormund           #+#    #+#             */
/*   Updated: 2019/12/30 15:07:26 by cormund          ###   ########.fr       */
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
		// if (*data != '\t')
		// 	*col += 4;
		// ++*col;
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

void	error_manager(char *error)
{
	int	ln;
	int	col;

	check_ln_col(&ln, &col, ASM_INPUT, ASM_DATA);
	ft_printf("%s [%d:%d]\n", error, ln, col);
	exit(-1);
}
