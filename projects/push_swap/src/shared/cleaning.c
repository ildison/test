/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:22:15 by cormund           #+#    #+#             */
/*   Updated: 2019/11/05 11:26:05 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

void	clean_stacks(t_stack *a, t_stack *b, int size_a, int size_b)
{
	t_stack		*tmp;

	if (a)
		while (size_a--)
		{
			tmp = a;
			a = a->next;
			ft_memdel((void *)&tmp);
		}
	if (b)
		while (size_b--)
		{
			tmp = b;
			b = b->next;
			ft_memdel((void *)&tmp);
		}
}
