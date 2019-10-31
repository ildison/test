/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_opers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:29:49 by cormund           #+#    #+#             */
/*   Updated: 2019/10/31 20:32:53 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_oper(t_oper **op, char *oper)
{
	t_oper	*tmp;

	if (!(tmp = *op))
	{
		if (!(*op = (t_oper *)ft_memalloc(sizeof(t_oper))))
			error(PS_ERROR_MALLOC);
		ft_strcpy((*op)->oper, oper);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(*tmp->oper == 'p' && *oper == 'p' && !ft_strequ(tmp->oper, oper))
		&& !(*tmp->oper == 'r' && *oper == 'r' && (tmp->oper[1] == oper[2]
												|| oper[1] == tmp->oper[2])))
		{
			tmp->next = (t_oper *)ft_memalloc(sizeof(t_oper));
			if (!tmp->next)
				error(PS_ERROR_MALLOC);
			ft_strcpy(tmp->next->oper, oper);
			tmp->next->prev = tmp;
		}
		else
			ft_memdel((void *)&tmp->prev->next);
	}
	printf("%s\n", oper);
}

void		ps_swap(t_ps *ps, t_stack **top)
{
	if (swap(top))
		IS_STACK_A(top) ? add_oper(&ps->opers, "sa") : add_oper(&ps->opers, "sb");
}

void		ps_push(t_ps *ps, t_stack **dst, t_stack **src)
{
	if (push(dst, src))
	{
		if (IS_STACK_A(dst))
		{
			add_oper(&ps->opers, "pa");
			++SIZE_A;
			--SIZE_B;
		}
		else
		{
			add_oper(&ps->opers, "pb");
			--SIZE_A;
			++SIZE_B;
		}
	}
}

void		ps_rotate(t_ps *ps, t_stack **top)
{
	if (rotate(top))
		IS_STACK_A(top) ? add_oper(&ps->opers, "ra") : add_oper(&ps->opers, "rb");
}

void		ps_reverse(t_ps *ps, t_stack **top)
{
	if (reverse(top))
		IS_STACK_A(top) ? add_oper(&ps->opers, "rra") : add_oper(&ps->opers, "rrb");
}
