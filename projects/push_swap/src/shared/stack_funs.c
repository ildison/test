/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:55:11 by cormund           #+#    #+#             */
/*   Updated: 2019/10/01 18:59:44 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

int			size_stack(t_stack *s)
{
	int		size;
	t_stack	*top;

	size = 0;
	if (s)
	{
		top = s;
		++size;
		while (s->next != top)
		{
			++size;
			s = s->next;
		}
	}
	return (size);
}

void		add_int_to_stack(t_stack **a, int num)
{
	t_stack	*lst;

	lst = *a;
	if (!lst)
	{
		if (!(*a = (t_stack *)ft_memalloc(sizeof(t_stack))))
			error(PS_ERROR_MALLOC);
		(*a)->num = num;
		(*a)->next = *a;
	}
	else
	{
		while (lst->next != *a)
			lst = lst->next;
		if (!(lst->next = (t_stack *)ft_memalloc(sizeof(t_stack))))
			error(PS_ERROR_MALLOC);
		lst->next->num = num;
		lst->next->next = *a;
		lst->next->prev = lst;
		(*a)->prev = lst->next;
	}
}
