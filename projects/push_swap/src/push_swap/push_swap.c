/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:54:07 by cormund           #+#    #+#             */
/*   Updated: 2019/10/03 10:56:36 by cormund          ###   ########.fr       */
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
	indexation(ps->a);

	//stdout indexs
	int size = size_stack(ps->a);
	while (size--)
	{
		printf("%d %d\n", ps->a->num, ps->a->i);
		ps->a = ps->a->next;
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
		push_swap(ac - 1, av + 1);
	return (0);
}
