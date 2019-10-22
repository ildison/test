/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:13:47 by cormund           #+#    #+#             */
/*   Updated: 2019/10/22 16:17:08 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visualizer.h"

short		*stack_cpy(t_stack *s)
{
	short	*stack;
	int		size_stack;
	int		i;

	size_stack = size_stack(s);
	if (size_stack)
		if (!(stack = (short *)ft_memalloc(sizeof(short) * (size_stack + 1))))
			error(PS_ERROR_MALLOC);
	i = 0;
	while (i < size_stack)
	{
		stack[i] = s->i;
		s = s->next;
		++i;
	}
}

t_step		*new_step(t_checker *chkr)
{
	t_step	*stp;


	if (!(stp = (t_step *)ft_memalloc(sizeof(t_step))))
		error(PS_ERROR_MALLOC);
	stp->a = stack_cpy(chkr->a);
	stp->b = stack_cpy(chkr->b);
	add_step();
}

t_step		*next_step(t_vis *vis, t_step *step, t_checker *chkr)
{
	char	b;

	if (step && step->next && !step->fin)
		return (step->next);
	else if (step && step->fin)
		return (step);
	else if (!read_operations(chkr, VISUAL_FLAG))
		add_new_step(chkr);
	return (step);
}