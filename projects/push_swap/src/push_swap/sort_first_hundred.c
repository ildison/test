/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first_hundred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:18:29 by cormund           #+#    #+#             */
/*   Updated: 2019/10/29 16:38:26 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		throwing_in_stack_b(t_ps *ps, t_splitter s)
{
	int			splt;

	splt = (s.min + s.split) / 2;
	while (SIZE_B < s.split)
	{
		if (TOP_A <= s.split)
		{
			ps_push(ps, STACK_B, STACK_A);
			if (TOP_B < splt)
				ps_rotate(ps, STACK_B);
		}
		else
			ps_rotate(ps, STACK_A);
	}
}

static int		depth_max_in_stack(t_ps *ps, t_max_min m)
{
	t_stack		*tmp;
	int			depth_rotate;
	int			depth_reverse;
	int			midl;

	tmp = ps->b;
	midl = SIZE_B / 2 + 1;
	depth_rotate = 0;
	while (tmp->i != m.max && tmp->i != m.pmax && tmp->next != ps->b && depth_rotate < midl)
	{
		++depth_rotate;
		tmp = tmp->next;
	}
	tmp = ps->b->prev;
	depth_reverse = 1;
	while (tmp->i != m.max && tmp->i != m.pmax && tmp->prev != ps->b && depth_rotate < midl)
	{
		++depth_reverse;
		tmp = tmp->prev;
	}
	return (depth_reverse > depth_rotate ? 0 : 1);
}

static void		push_max_min(t_ps *ps, t_max_min m)
{
	int			reverse;

	reverse = depth_max_in_stack(ps, m);
	if (reverse)
		while (TOP_B != m.max && TOP_B != m.pmax && TOP_B != m.min && TOP_B != m.pmin)
			ps_reverse(ps, STACK_B);
	else
		while (TOP_B != m.max && TOP_B != m.pmax && TOP_B != m.min && TOP_B != m.pmin)
			ps_rotate(ps, STACK_B);
	ps_push(ps, STACK_A, STACK_B);
}

static void		back_to_a(t_ps *ps, t_max_min m)
{
	int			count_hiden;

	count_hiden = 0;
	while (m.pmax >= m.pmin)
	{
		push_max_min(ps, m);
		if (TOP_A == m.max)
		{
			DECREMENT_MAX(m.max, m.pmax);
			if (SECOND_A == m.max)
				DECREMENT_MAX(m.max, m.pmax);
		}
		else if (TOP_A != m.pmax && (TOP_A == m.min || TOP_A == m.pmin))
		{
			++count_hiden;
			if (TOP_A == m.min)
				INCREMENT_MIN(m.min, m.pmin);
			if (PRELAST_A == m.min)
				INCREMENT_MIN(m.min, m.pmin);
			ps_rotate(ps, STACK_A);
		}
		if (TOP_A > SECOND_A && SIZE_B && TOP_B < SECOND_B)
			ps_swap(ps, STACK_B);
		if (TOP_A > SECOND_A)
			ps_swap(ps, STACK_A);

	}
	while (count_hiden--)
	{
		ps_reverse(ps, STACK_A);
			if (TOP_A > SECOND_A)
		ps_swap(ps, STACK_A);
	}
}

void			sort_first_hundred(t_ps *ps, t_splitter s, int max)
{
	int			next_split;

	if (SIZE_A <= 3)
		sort_three_elem(ps, STACK_A, SIZE_A);
	else
	{
		throwing_in_stack_b(ps, s);
		next_split = s.split + s.split / 2 > max ? max : s.split + s.split / 2;
		sort_first_hundred(ps, (t_splitter){next_split, s.split + 1}, max);
		back_to_a(ps, (t_max_min){s.split, s.split - 1, s.min, s.min + 1});
	}
}