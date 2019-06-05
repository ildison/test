/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:07:38 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 13:01:43 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (new && alst)
	{
		lst = *alst;
		if (!lst)
		{
			lst = new;
			new->next = NULL;
		}
		else
		{
			while (lst->next)
				lst = lst->next;
			lst->next = new;
			new->next = NULL;
		}
	}
}
