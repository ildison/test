/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_opers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:29:49 by cormund           #+#    #+#             */
/*   Updated: 2019/10/29 16:24:57 by cormund          ###   ########.fr       */
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
		tmp->next = (t_oper *)ft_memalloc(sizeof(t_oper));
		if (!(tmp = tmp->next))
			error(PS_ERROR_MALLOC);
		ft_strcpy(tmp->oper, oper);
	}
}

int			ps_swap(t_ps *ps, t_stack **top)
{
	if (swap(top))
	{
		*top == ps->a ? add_oper(&ps->opers, "sa") : add_oper(&ps->opers, "sb");
		return (1);
	}
	return (0);
}

void		ps_push(t_ps *ps, t_stack **dst, t_stack **src)
{
	if (push(dst, src))
	{
		if (*dst == ps->a)
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
		*top == ps->a ? add_oper(&ps->opers, "ra") : add_oper(&ps->opers, "rb");
}

void		ps_reverse(t_ps *ps, t_stack **top)
{
	if (reverse(top))
		*top == ps->a ? add_oper(&ps->opers, "rra") : add_oper(&ps->opers, "rrb");
}
