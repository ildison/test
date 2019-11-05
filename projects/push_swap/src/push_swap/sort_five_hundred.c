/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:10:53 by cormund           #+#    #+#             */
/*   Updated: 2019/11/05 15:16:18 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		low_i(t_stack *s, int size)
{
	int			min;

	min = 0;
	if (s)
	{
		min = s->i;
		while (size)
		{
			s = s->next;
			if (s->i < min)
				min = s->i;
			--size;
		}
	}
	return (min);
}

static int		high_i(t_stack *s, int size)
{
	int			max;

	max = 0;
	if (s)
	{
		max = s->i;
		while (size)
		{
			s = s->next;
			if (s->i > max)
				max = s->i;
			--size;
		}
	}
	return (max);
}

static void		sort_three_elem_des(t_ps *ps, t_stack **stk, int sz)
{
	if (size_stack(*stk) <= 3)
		while (check_des_sorted(*stk, 0, sz))
			if ((*stk)->i > (*stk)->next->i && sz != 2)
				ps_reverse(ps, stk);
			else if (sz == 2 || (*stk)->i > (*stk)->next->next->i)
				ps_swap(ps, stk);
			else
				ps_rotate(ps, stk);
	else
		while (check_des_sorted(*stk, 0, sz))
			if ((*stk)->i < (*stk)->next->i)
				ps_swap(ps, stk);
			else if ((*stk)->i > (*stk)->next->i)
			{
				ps_rotate(ps, stk);
				ps_swap(ps, stk);
				ps_reverse(ps, stk);
			}
			else
			{
				ps_reverse(ps, stk);
				ps_swap(ps, stk);
				ps_rotate(ps, stk);
			}
}

static int		throwing_in_stack_b(t_ps *ps, t_stack **a, t_stack **b,\
																int size)
{
	int			pivot;
	int			count_push;
	int			count_rotate;

	pivot = ps->a == *a ? low_i(*a, size) : high_i(*a, size);
	pivot += ps->a == *a ? size / 2 : -(size / 2);
	count_push = 0;
	count_rotate = 0;
	while (size--)
		if ((ps->a == *a && (*a)->i <= pivot) || (ps->b == *a &&\
														(*a)->i >= pivot))
		{
			ps_push(ps, b, a);
			(*b)->i == pivot ? ps_rotate(ps, b) : ++count_push;
		}
		else
		{
			ps_rotate(ps, a);
			++count_rotate;
		}
	if (size_stack(*a) > count_rotate)
		while (count_rotate--)
			ps_reverse(ps, a);
	return (count_push);
}

void			sort_five_hundred(t_ps *ps, t_stack **a, t_stack **b, int size)
{
	int			count_push;

	if (size == 2 && ((ps->a == *a && (*a)->i > (*a)->next->i) ||\
						(ps->b == *a && (*a)->i < (*a)->next->i)))
		ps_swap(ps, a);
	else if (size == 3)
		ps->a == *a ? sort_three_elem(ps, a, 3) : sort_three_elem_des(ps, a, 3);
	else if (size > 3)
	{
		count_push = throwing_in_stack_b(ps, a, b, size);
		sort_five_hundred(ps, a, b, size - count_push - 1);
		ps_reverse(ps, b);
		ps_push(ps, a, b);
		sort_five_hundred(ps, b, a, count_push);
		while (count_push--)
			ps_push(ps, a, b);
	}
}
