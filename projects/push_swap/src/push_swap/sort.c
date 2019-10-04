/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:55:23 by cormund           #+#    #+#             */
/*   Updated: 2019/10/04 19:12:04 by cormund          ###   ########.fr       */
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

void		throwing_in_stack_b(t_ps *ps, t_stack **a, t_stack **b)
{
	int		max;
	int		pmax;

	max = PS_MAX_INDEX_IN_STACK_B;
	pmax = PS_PREVIOUS_MAX;
	while (ps->sz_a > 3)
	{
		if ((*a)->i <= max && --ps->sz_a && ++ps->sz_b)
			ps_push(ps, b, a);
		else if ((*a)->i > max)
			ps_rotate(ps, a);
		if (*b && ((*b)->i == max || (*b)->i == pmax) && ps->sz_a > 5)
			ps_rotate(ps, b);
	}
}

void		sort_first_hundred(t_ps *ps, t_stack **a, t_stack **b)
{
	int		max;
	int		pmax;
	int		min;

	max = PS_MAX_INDEX_IN_STACK_B;
	pmax = PS_PREVIOUS_MAX;
	min = PS_FIRST_INDEX;
	throwing_in_stack_b(ps, a, b);
	sort_three_elem(ps, &ps->a, 3);
	while (ps->sz_b)
	{
		ascend_max_pmax_min(ps, b, max, min);
		ps_push(ps, a, b);
		ps->sz_b--;
		if ((*a)->i == min && (min != pmax && min != max))
		{
			ps_rotate(ps, a);
			if (*b && (*b)->i != max && ((*b)->next->i == max || (*b)->next->i == pmax || (*b)->next->i == min))
				ps_rotate(ps, b);
			++min;
		}
		else if ((*a)->i == max)
		{
			--max;
			--pmax;
		}
		if ((*a)->i > (*a)->next->i)
		{
			ps_swap(ps, a);
			if (*b && (*b)->i != max && ((*b)->next->i == max || (*b)->next->i == pmax || (*b)->next->i == min))
				ps_swap(ps, b);
		}
	}
}
			// (*b)->i < (*b)->next->i ? ps_swap(ps, b) : 0;

void		sort(t_ps *ps)
{
	if (ps->sz_a <= 3)
		sort_three_elem(ps, &ps->a, ps->sz_a);
	else if (ps->sz_a <= 100)
		sort_first_hundred(ps, &ps->a, &ps->b);
}