/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:54:07 by cormund           #+#    #+#             */
/*   Updated: 2019/11/05 11:35:12 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		cleaning_up(t_ps *ps)
{
	clean_stacks(STK_A, STK_B, SIZE_A, SIZE_B);
	free(ps);
}

static void		print_and_clean_opers(t_oper *opers)
{
	t_oper		*tmp;

	while (opers)
	{
		printf("%s\n", opers->oper);
		tmp = opers;
		opers = opers->next;
		free(tmp);
	}
}

static void		push_swap(int n_arg, char **arg)
{
	t_ps		*ps;

	ps = (t_ps *)ft_memalloc(sizeof(t_ps));
	if (!ps)
		error(PS_ERROR_MALLOC);
	read_arg(STACK_A, n_arg, arg, 0);
	SIZE_A = size_stack(ps->a);
	SIZE_B = 0;
	if (SIZE_A > 1 && check_sorted(ps->a, 0, SIZE_A))
	{
		indexation(ps->a, SIZE_A);
		sort(ps);
		optimization_opers(ps->opers);
		print_and_clean_opers(ps->opers);
	}
	cleaning_up(ps);
}

int				main(int ac, char **av)
{
	if (ac > 1)
		push_swap(ac - 1, av + 1);
	return (0);
}
