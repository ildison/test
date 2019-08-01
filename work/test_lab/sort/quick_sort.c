/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:32:27 by cormund           #+#    #+#             */
/*   Updated: 2019/07/31 12:35:42 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			*ft_partition(int *mas, int *left, int *right)
{
	int		pivot;

	pivot = mas[(right - left) / 2];
	while (left < right)
	{
		while (*left < pivot)
			++left;
		while (*right > pivot)
			--right;
		if (left <= right)
		{
			*left ^= *right;
			*right ^= *left;
			*left ^= *right;
			++left;
			--right;
		}
	}
	return (right);
}

void		quick_sort(int *mas, int *left, int *right)
{
	int		*p;

	if (left >= right)
		return ;
	p = ft_partition(mas, left, right);
	quick_sort(mas, left, p - 1);
	quick_sort(mas, p + 1, right);
}

int			*collection_array(char **av, int n)
{
	int		*mas;
	int		i;

	i = 0;
	mas = (int *)malloc(sizeof(int) * n);
	while (n)
	{
		mas[i] = atoi(av[i]);
		++i;
		--n;
	}
	return (mas);
}

int			main(int ac, char **av)
{
	int		*mas;

	if (ac > 1)
	{
		mas = collection_array(av + 1, ac - 1);
		quick_sort(mas, mas, mas + ac - 2);
	}
	return (0);
}