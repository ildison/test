/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:13:47 by cormund           #+#    #+#             */
/*   Updated: 2019/10/23 17:17:21 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visualizer.h"

short		*stack_cpy(t_stack *s)
{
	short	*stack;
	int		sz_stack;
	int		i;

	stack = NULL;
	sz_stack = size_stack(s);
	if (sz_stack)
		if (!(stack = (short *)ft_memalloc(sizeof(short) * (sz_stack + 1))))
			error(PS_ERROR_MALLOC);
	i = 0;
	while (i < sz_stack)
	{
		stack[i] = s->i;
		s = s->next;
		++i;
	}
	return (stack);
}

void		add_step(t_step *new_step, t_step **first_stp)
{
	t_step	*tmp;

	tmp = *first_stp;
	if (!tmp)
		*first_stp = new_step;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_step;
		new_step->prev = tmp;
	}
}

t_step		*new_step(t_checker *chkr, t_step **first_stp)
{
	t_step	*stp;


	if (!(stp = (t_step *)ft_memalloc(sizeof(t_step))))
		error(PS_ERROR_MALLOC);
	stp->a = stack_cpy(chkr->a);
	stp->b = stack_cpy(chkr->b);
	add_step(stp, first_stp);
	return (stp);
}

t_step		*next_step(t_vis *vis, t_step *step, t_checker *chkr)
{
	if (step && step->next && !step->fin)
		return (step->next);
	else if (step && step->fin)
		return (step);
	else if (read_operations(chkr, VISUAL_FLAG))
		step = new_step(chkr, &vis->first_step);
	else
		step->fin = 1;
	return (step);
}