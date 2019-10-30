/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:55:23 by cormund           #+#    #+#             */
/*   Updated: 2019/10/30 14:31:54 by cormund          ###   ########.fr       */
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
	t_splitter	s;


	if (SIZE_A <= 3)
		sort_three_elem(ps, STACK_A, SIZE_A);
	else if (SIZE_A <= 100)
	{
		s.split = PS_MAX_INDEX_IN_STACK_B / 2;
		s.min = PS_FIRST_INDEX;
		sort_first_hundred(ps, s, PS_MAX_INDEX_IN_STACK_B);
	}
	else
	{
		s.split = SIZE_A / 3;
		s.min = PS_FIRST_INDEX;
		sort_five_hundred(ps, s, SIZE_A);
			while (TOP_A != PS_FIRST_INDEX)
		ps_reverse(ps, STACK_A);
	}
}