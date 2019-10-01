/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:07:40 by cormund           #+#    #+#             */
/*   Updated: 2019/10/01 15:47:05 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int				check_sorted(t_stack *a, t_stack *b)
{
	t_stack		*top;

	if (b)
		return(1);
	top = a;
	while (a->next != top)
	{
		if (a->num > a->next->num)
			return (1);
		a = a->next;
	}
	return (0);
}

void			checker(int n_arg, char **arg)
{
	t_checker	*chkr;

	chkr = (t_checker *)ft_memalloc(sizeof(t_checker));
	if (!chkr)
		error(PS_ERROR_MALLOC);
	read_arg(&chkr->a, n_arg, arg, &chkr->flags);
	read_operations(chkr);
	check_sorted(chkr->a, chkr->b) ? PS_KO : PS_OK;
}

int			main(int ac, char **av)
{
	if (ac > 1)
		checker(ac - 1, av + 1);
	return (0);
}