/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:55:23 by cormund           #+#    #+#             */
/*   Updated: 2019/10/04 12:55:34 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_three_elem(t_ps *ps, t_stack **stk, int sz)
{
	while (check_sorted(*stk, 0, sz))
	{
		if ((*stk)->i < (*stk)->next->i || sz == 2)
			ps_reverse(ps, stk);
		else if ((*stk)->i < (*stk)->next->next->i)
			ps_swap(ps, stk);
		else
			ps_rotate(ps, stk);
	}
}

void		sort(t_ps *ps)
{
	if (ps->sz_a <= 3)
		sort_three_elem(ps, &ps->a, ps->sz_a);
}