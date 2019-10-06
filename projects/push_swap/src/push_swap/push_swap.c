/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:54:07 by cormund           #+#    #+#             */
/*   Updated: 2019/10/06 21:44:01 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_opers(t_oper *opers)
{
	while (opers)
	{
		printf("%s\n", opers->oper);
		opers = opers->next;
	}
}

static void		push_swap(int n_arg, char **arg)
{
	t_ps		*ps;

	ps = (t_ps *)ft_memalloc(sizeof(t_ps));
	if (!ps)
		error(PS_ERROR_MALLOC);
	read_arg(&ps->a, n_arg, arg, 0);
	ps->sz_a = size_stack(ps->a);
	if (ps->sz_a > 1 && check_sorted(ps->a, 0, ps->sz_a))
	{
		indexation(ps->a, ps->sz_a);
		sort(ps);
		// print_opers(ps->opers);
		// printf("---------------\n");
		optimization_opers(ps->opers);
		print_opers(ps->opers);
	}

	// int i = 0;
	// while (i < ps->sz_a)
	// {
	// 	printf("%d ", ps->a->num);
	// 	++i;
	// 	ps->a = ps->a->next;
	// }
	// printf("\n");
	// i = 0;
	// while (i < ps->sz_b)
	// {
	// 	printf("%d ", ps->b->num);
	// 	++i;
	// 	ps->b = ps->b->next;
	// }
}

int				main(int ac, char **av)
{
	if (ac > 1)
		push_swap(ac - 1, av + 1);
	return (0);
}
