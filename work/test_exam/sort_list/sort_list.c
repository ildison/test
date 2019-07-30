/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:07:20 by cormund           #+#    #+#             */
/*   Updated: 2019/07/30 14:25:03 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// void		sort_direct_selection(t_list* min_max, t_list* lst, int (*cmp)(int, int))
// {
// 	if (!lst)
// 		return ;
// 	if (!cmp(min_max->data, lst->data))
// 	{
// 	}
// }

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*begin;

	begin = lst;
	if (!lst->next)
		return (begin);
	
}

int			main()
{
	t_list	*lst;
	sort_list(lst, ascending);
	return (0);
}