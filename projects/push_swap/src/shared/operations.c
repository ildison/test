/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 09:33:33 by cormund           #+#    #+#             */
/*   Updated: 2019/10/01 12:13:37 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

void		swap(t_stack **top)
{
	if (*top && (*top)->next != *top)
		ft_swap(&(*top)->num, &(*top)->next->num);
}

void		push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp_s;

	if ((tmp_s = *src))
	{
		if (tmp_s->next != tmp_s)
		{
			tmp_s->next->prev = tmp_s->prev;
			tmp_s->prev->next = tmp_s->next;
			*src = tmp_s->next;
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
}

void		rotate(t_stack **top)
{
	if (*top && (*top)->next != *top)
		*top = (*top)->next;
}

void		reverse(t_stack **top)
{
	if (*top && (*top)->next != *top)
		*top = (*top)->prev;
}