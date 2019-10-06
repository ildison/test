/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_opers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:54:53 by cormund           #+#    #+#             */
/*   Updated: 2019/10/06 21:43:26 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		delete_oper(t_oper *prev, t_oper *op)
{
	t_oper	*tmp;

	tmp = op;
	prev->next = op->next;
	free(op);
}

void		check_opers(t_oper *op, char *oper)
{
	t_oper	*tmp;

	tmp = op;
	if (*(oper + 1) == 'a' || *(oper + 2) == 'a')
		while (op->next && IS_OPER_OF_STACK_A && *op->next->oper != 'p')
			op = op->next;
	else
		while (op->next && IS_OPER_OF_STACK_B && *op->next->oper != 'p')
			op = op->next;
	if (op->next && *op->next->oper != 'p')
	{
		if (*oper == 's' && *op->next->oper == 's')
		{
			ft_strcpy(tmp->oper, SS);
			delete_oper(op, op->next);
		}
		else if (ft_strnequ(op->next->oper, RR, 2) && ft_strnequ(oper, RR, 2))
		{
			ft_strcpy(tmp->oper, RRR);
			delete_oper(op, op->next);
		}
		else if (*op->next->oper == 'r' && *oper == 'r' &&\
								ft_strlen(op->next->oper) == ft_strlen(oper))
		{
			ft_strcpy(tmp->oper, RR);
			delete_oper(op, op->next);
		}
	}
}

void		optimization_opers(t_oper *op)
{
	while (op)
	{
		if ((*op->oper == 's' || *op->oper == 'r') && (*(op->oper + 1) != 's' && *(op->oper + 2) != 'r' && !ft_strequ(op->oper, RR)))
			check_opers(op, op->oper);
		op = op->next;
	}
}
