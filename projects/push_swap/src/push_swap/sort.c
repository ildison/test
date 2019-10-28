/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:55:23 by cormund           #+#    #+#             */
/*   Updated: 2019/10/28 16:59:36 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three_elem(t_ps *ps, t_stack **stk, int sz)
{
	while (check_sorted(*stk, 0, sz))
	{
		if ((*stk)->i < (*stk)->next->i && sz != 2)
			ps_reverse(ps, stk);
		else if (sz == 2 || (*stk)->i < (*stk)->next->next->i)
			ps_swap(ps, stk);
		else
			ps_rotate(ps, stk);
	}
}

void		sort(t_ps *ps)
{
	t_max_min	m;


	if (SIZE_A <= 3)
		sort_three_elem(ps, STACK_A, SIZE_A);
	else if (SIZE_A <= 100)
	{
		m.max = PS_MAX_INDEX_IN_STACK_B;
		m.split = m.max / 2 + m.max % 2;
		m.min = PS_FIRST_INDEX;
		sort_first_hundred(ps, m);
	}
	else
	{
		m.max = PS_MAX_INDEX_IN_STACK_B;
		m.split = m.max / 2 + m.max % 2;
		m.min = PS_FIRST_INDEX;
		sort_first_hundred(ps, m);
	}
}