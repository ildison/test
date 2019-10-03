/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:55:11 by cormund           #+#    #+#             */
/*   Updated: 2019/10/03 19:10:01 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

int				check_sorted(t_stack *a, t_stack *b, int sz)
{
	int			i;

	if (b)
		return (1);
	i = 1;
	while (i < sz)
	{
		if (a->num > a->next->num)
			return (1);
		a = a->next;
		++i;
	}
	return (0);
}

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
