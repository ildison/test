/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:55:23 by cormund           #+#    #+#             */
/*   Updated: 2019/10/03 19:11:18 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_three_elem(t_stack **stk, int sz)
{
	while (check_sorted(*stk, 0, sz))
	{
		printf("here\n");
		if ((*stk)->i < (*stk)->next->i || sz == 2)
			reverse(stk);
		else if ((*stk)->i < (*stk)->next->next->i)
			swap(stk);
		else
			rotate(stk);
	}
}

void		sort(t_ps *ps)
{
	if (ps->sz_a <= 3)
		sort_three_elem(&ps->a, ps->sz_a);
}