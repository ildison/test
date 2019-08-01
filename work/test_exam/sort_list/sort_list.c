/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:07:20 by cormund           #+#    #+#             */
/*   Updated: 2019/07/31 15:15:27 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		print_lst(t_list *lst)
{
	while (lst->next)
	{
		printf("%d ", lst->data);
		lst = lst->next;
	}
	printf("%d\n", lst->data);
}

t_list		*ft_new_elem(int num)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->data = num;
	lst->next = NULL;
	return (lst);
}

t_list		*collection_array(t_list* lst, char **av, int n)
{
	t_list	*begin;
	int		i;

	i = 0;
	lst = ft_new_elem(atoi(av[i++]));
	begin = lst;
	while (--n)
	{
		lst->next = ft_new_elem(atoi(av[i]));
		++i;
		lst = lst->next;
	}
	return (begin);
}

void		ft_swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void		sort_direct_selection(int* min_max, t_list* lst, int (*cmp)(int, int))
{
	if (!lst)
		return ;
	if (!cmp(*min_max, lst->data))
		ft_swap(min_max, &lst->data);
	sort_direct_selection(min_max, lst->next, cmp);
}

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*begin;

	begin = lst;
	while (lst->next)
	{
		sort_direct_selection(&lst->data, lst->next, cmp);
		lst = lst->next;
	}
	return (begin);
}

int			main(int ac, char **av)
{
	t_list	*lst;

	if (ac > 1)
	{
		lst = collection_array(lst, av + 1, ac - 1);
		sort_list(lst, ascending);
		print_lst(lst);
	}
	return (0);
}