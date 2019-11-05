/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:25:39 by cormund           #+#    #+#             */
/*   Updated: 2019/11/05 15:25:45 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

int			swap(t_stack **top)
{
	if (*top && (*top)->next != *top)
	{
		ft_swap(&(*top)->num, &(*top)->next->num);
		ft_swap(&(*top)->i, &(*top)->next->i);
		return (1);
	}
	return (0);
}

int			push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp_s;

	if ((tmp_s = *src))
	{
		if (tmp_s->next != tmp_s)
		{
			tmp_s->next->prev = tmp_s->prev;
			tmp_s->prev->next = tmp_s->next;
		}
		*src = tmp_s->next != tmp_s ? tmp_s->next : NULL;
		if (*dst)
		{
			tmp_s->prev = (*dst)->prev;
			tmp_s->next = *dst;
			(*dst)->prev->next = tmp_s;
			(*dst)->prev = tmp_s;
		}
		else
		{
			tmp_s->next = tmp_s;
			tmp_s->prev = tmp_s;
		}
		*dst = tmp_s;
	}
	return (tmp_s ? 1 : 0);
}

int			rotate(t_stack **top)
{
	if (*top && (*top)->next != *top)
	{
		*top = (*top)->next;
		return (1);
	}
	return (0);
}

int			reverse(t_stack **top)
{
	if (*top && (*top)->next != *top)
	{
		*top = (*top)->prev;
		return (1);
	}
	return (0);
}
