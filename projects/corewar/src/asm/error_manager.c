/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:28:36 by cormund           #+#    #+#             */
/*   Updated: 2019/12/24 18:14:08 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_ln_col(int *ln, int *col, char *data, char *ptr_error)
{
	*ln = 1;
	*col = 1;
	while (*data)
	{
		if (data == ptr_error)
			break ;
		++*col;
		if (*data == '\n')
		{
			++*ln;
			*col = 1;
		}
		++data;
	}
}

void	error_manager(char *error, char *data, char *ptr_error)
{
	int	ln;
	int	col;

	check_ln_col(&ln, &col, data, ptr_error);
	ft_printf("%s [%d:%d]\n", error, ln, col);
	exit(-1);
}
