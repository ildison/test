/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:54:07 by cormund           #+#    #+#             */
/*   Updated: 2019/10/03 18:44:44 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(int n_arg, char **arg)
{
	t_ps	*ps;

	ps = (t_ps *)ft_memalloc(sizeof(t_ps));
	if (!ps)
		error(PS_ERROR_MALLOC);
	read_arg(&ps->a, n_arg, arg, 0);
	ps->sz_a = size_stack(ps->a);
	if (ps->sz_a > 1 && check_sorted(ps->a, 0, ps->sz_a))
	{
		indexation(ps->a, ps->sz_a);
		sort(ps);
	}

	int i = 0;
	while (i < ps->sz_a)
	{
		printf("%d ", ps->a->num);
		++i;
		ps->a = ps->a->next;
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
		push_swap(ac - 1, av + 1);
	return (0);
}
