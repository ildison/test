/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:10:53 by cormund           #+#    #+#             */
/*   Updated: 2019/10/29 18:12:37 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		throwing_in_stack_b(t_ps *ps, t_splitter s, char flag)
{
	int			splt;

	if (flag)
		splt = (s.min + s.split) / 2;
	while (SIZE_B < (s.split - 1))
	{
		if (TOP_A <= s.split && TOP_A != PS_FIRST_INDEX)
		{
			ps_push(ps, STACK_B, STACK_A);
			if (flag && TOP_B < splt)
				ps_rotate(ps, STACK_B);
		}
		else
			ps_rotate(ps, STACK_A);
	}
}

static void		back_to_a(t_ps *ps, int min)
{
	while (SIZE_B >= min)
	{
		while (TOP_B < TOP_A && TOP_B < LAST_A)
			ps_reverse(ps, STACK_A);
		while (TOP_B > TOP_A)
			ps_rotate(ps, STACK_A);
		ps_push(ps, STACK_A, STACK_B);
	}
}

void			sort_five_hundred(t_ps *ps, t_splitter s, int max)
{
	int			next_split;

	if (SIZE_A > 2)
	{
		throwing_in_stack_b(ps, s, (s.split <= (max + 1) / 3) ? 1 : 0);
		next_split = s.split + s.split / 2 >= max ? max - 1 : s.split + s.split / 2;
		sort_five_hundred(ps, (t_splitter){next_split, s.split + 1}, max);
		back_to_a(ps, s.min);
	}
}