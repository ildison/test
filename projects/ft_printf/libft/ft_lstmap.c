/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 10:35:59 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/23 11:50:55 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin_list;
	t_list *res;
	t_list *tmp;

	begin_list = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = (*f)(lst);
		if (!tmp)
		{
			while (begin_list)
			{
				res = begin_list->next;
				free(begin_list->content);
				free(begin_list);
				begin_list = res;
			}
			return (NULL);
		}
		ft_lstadd_end(&begin_list, tmp);
		lst = lst->next;
	}
	return (begin_list);
}
