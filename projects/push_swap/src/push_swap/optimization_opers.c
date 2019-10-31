/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_opers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:54:53 by cormund           #+#    #+#             */
/*   Updated: 2019/10/31 17:13:28 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		delete_oper(t_oper *prev, t_oper *op)
{
	t_oper	*tmp;

	tmp = op;
	prev->next = op->next;
	free(op);
}

// static void		check_collision(t_oper *op, char *oper)
// {
// 	t_oper		*tmp;

// 	tmp = op->next;
// 	if (*oper == 'p' && IS_OPER_OF_STACK_A)
// 		while (tmp->next && IS_OPER_OF_STACK_A && tmp->oper == 'p')
// }

static void		check_opers(t_oper *op, char *oper)
{
	t_oper		*tmp;
	char		*new_oper;

	tmp = op;
	if (*(oper + 1) == 'a' || *(oper + 2) == 'a')
		while (op->next && IS_OPER_OF_STACK_A && *op->next->oper != 'p')
			op = op->next;
	else
		while (op->next && IS_OPER_OF_STACK_B && *op->next->oper != 'p')
			op = op->next;
	new_oper = NULL;
	if (op->next && *oper == 's' && *op->next->oper == 's')
		new_oper = SS;
	else if (op->next && ft_strnequ(op->next->oper, RR, 2) &&\
												ft_strnequ(oper, RR, 2))
		new_oper = RRR;
	else if (op->next && *op->next->oper == 'r' && *oper == 'r' &&\
							ft_strlen(op->next->oper) == ft_strlen(oper))
		new_oper = RR;
	if (new_oper)
	{
		ft_strcpy(tmp->oper, new_oper);
		delete_oper(op, op->next);
	}
}

void			optimization_opers(t_oper *op)
{
	while (op)
	{
		// if (op->next && *op->next->oper == 'p' || *op->next->oper == 'r')
		// 	check_push_collision(op, op->next->oper);
		// if (op->next && *op->next->oper == 'r')
		// 	check_r_rr_collision(op, op->next->oper);
		if (*op->oper == 's' || *op->oper == 'r')
			check_opers(op, op->oper);
		op = op->next;
	}
}
