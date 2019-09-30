/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:07:40 by cormund           #+#    #+#             */
/*   Updated: 2019/09/30 19:15:28 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

void			checker(int n_arg, char **arg)
{
	t_checker	*chkr;
	t_stack		*b;

	chkr = (t_checker *)ft_memalloc(sizeof(t_checker));
	read_arg(&chkr->a, n_arg, arg, &chkr->flags);
	b = chkr->a;
	printf("%d ", b->num);
	b = b->next;
	while (b != chkr->a)
	{
		printf("%d ", b->num);
		b = b->next;
	}
}

int			main(int ac, char **av)
{
	if (ac > 1)
		checker(ac - 1, av + 1);
	return (0);
}