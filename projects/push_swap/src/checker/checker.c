/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:07:40 by cormund           #+#    #+#             */
/*   Updated: 2019/11/05 11:27:38 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

static void		cleaning_up(t_checker *chkr)
{
	clean_stacks(chkr->a, chkr->b, size_stack(chkr->a), size_stack(chkr->b));
	free(chkr);
}

static void		checker(int n_arg, char **arg)
{
	t_checker	*chkr;

	chkr = (t_checker *)ft_memalloc(sizeof(t_checker));
	if (!chkr)
		error(PS_ERROR_MALLOC);
	read_arg(&chkr->a, n_arg, arg, &chkr->flags);
	if (VISUALIZATION_MODE)
	{
		indexation(chkr->a, size_stack(chkr->a));
		visualiser(chkr);
	}
	else if (chkr->a)
		read_operations(chkr, !VISUAL_FLAG);
	check_sorted(chkr->a, chkr->b, size_stack(chkr->a)) ? PS_KO : PS_OK;
	cleaning_up(chkr);
}

int				main(int ac, char **av)
{
	if (ac > 1)
		checker(ac - 1, av + 1);
	return (0);
}
