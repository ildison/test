/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:52:15 by cormund           #+#    #+#             */
/*   Updated: 2019/10/01 21:00:28 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

static int	get_pivot(int *mas, int left, int right)
{
	int		mid;

	mid = (left + right) / 2;
	if (mas[left] < mas[right])
		ft_swap(&mas[left], &mas[right]);
	if (mas[mid] < mas[left])
		ft_swap(&mas[left], &mas[mid]);
	if (mas[mid] > mas[right])
		ft_swap(&mas[mid], &mas[right]);
	return (mas[mid]);
}

static int	partition(int *mas, int l, int r)
{
	int		pivot;

	pivot = get_pivot(mas, l, r);
	while (l <= r)
	{
		while (mas[l] < pivot)
			++l;
		while (mas[r] > pivot)
			--r;
		if (l >= r)
			return (r);
		ft_swap(&mas[l], &mas[r]);
	}
	return (r);
}

void		qsort(int *mas, int left, int right)
{
	int		p;

	if (left < right)
	{
		p = partition(mas, left, right);
		qsort(mas, left, p - 1);
		qsort(mas, p + 1, right);
	}
}
