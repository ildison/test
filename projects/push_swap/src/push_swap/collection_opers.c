/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_opers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:29:49 by cormund           #+#    #+#             */
/*   Updated: 2019/10/04 12:54:44 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_oper(t_oper **op, char *oper)
{
	t_oper	*tmp;

	if (!*op)
	{
		*op = (t_oper *)ft_memalloc(sizeof(t_oper));
		if (!oper)
			error(PS_ERROR_MALLOC);
		ft_strcpy((*op)->oper, oper);
	}
	else
	{
		tmp = *op;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_oper *)ft_memalloc(sizeof(t_oper));
		if (!oper)
			error(PS_ERROR_MALLOC);
		ft_strcpy(tmp->next->oper, oper);
	}
}

void		ps_swap(t_ps *ps, t_stack **top)
{
	*top == ps->a ? push_oper(&ps->opers, "sa") : push_oper(&ps->opers, "sb");
	swap(top);
}

void		ps_push(t_ps *ps, t_stack **dst, t_stack **src)
{
	*dst == ps->a ? push_oper(&ps->opers, "pa") : push_oper(&ps->opers, "pb");
	push(dst, src);
}

void		ps_rotate(t_ps *ps, t_stack **top)
{
	*top == ps->a ? push_oper(&ps->opers, "ra") : push_oper(&ps->opers, "rb");
	rotate(top);
}

void		ps_reverse(t_ps *ps, t_stack **top)
{
	*top == ps->a ? push_oper(&ps->opers, "rra") : push_oper(&ps->opers, "rrb");
	reverse(top);
}
