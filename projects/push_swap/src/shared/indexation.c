/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:52:15 by cormund           #+#    #+#             */
/*   Updated: 2019/10/03 11:48:41 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

static void	swap_pointer(t_stack **p1, t_stack **p2)
{
	void	*tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

static int	get_pivot(t_stack **mas, int left, int right)
{
	int		mid;

	mid = (left + right) / 2;
	if (mas[left]->num > mas[right]->num)
		swap_pointer(&mas[left], &mas[right]);
	if (mas[mid]->num < mas[left]->num)
		swap_pointer(&mas[left], &mas[mid]);
	if (mas[mid]->num > mas[right]->num)
		swap_pointer(&mas[mid], &mas[right]);
	return (mas[mid]->num);
}

static int	partition(t_stack **mas, int l, int r)
{
	int		pivot;

	pivot = get_pivot(mas, l, r);
	while (l <= r)
	{
		while (mas[l]->num < pivot)
			++l;
		while (mas[r]->num > pivot)
			--r;
		if (l >= r)
			return (r);
		swap_pointer(&mas[l], &mas[r]);
	}
	return (r);
}

static void	q_sort(t_stack **mas, int left, int right)
{
	int		p;

	if (left < right)
	{
		p = partition(mas, left, right);
		q_sort(mas, left, p - 1);
		q_sort(mas, p + 1, right);
	}
}

void		indexation(t_stack *stk, int size)
{
	t_stack	**mas;
	int		i;

	mas = (t_stack **)malloc(sizeof(t_stack *) * size);
	if (!mas)
		error(PS_ERROR_MALLOC);
	i = 0;
	while (i < size)
	{
		mas[i] = stk;
		++i;
		stk = stk->next;
	}
	q_sort(mas, 0, size - 1);
	while (size--)
		mas[size]->i = i--;
	free(mas);
}