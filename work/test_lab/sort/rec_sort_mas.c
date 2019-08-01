/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_sort_mas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:51:39 by cormund           #+#    #+#             */
/*   Updated: 2019/07/30 11:08:17 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rec_sort(int *min, int *mas, int size)
{
	if (!size)
		return ;
	if (*mas < *min)
	{
		*mas ^= *min;
		*min ^= *mas;
		*mas ^= *min;
	}
	ft_rec_sort(min, mas + 1, size - 1);
}

void	ft_rec_direct_selection(int	*mas, int size)
{
	int	*min;

	if (size == 1)
		return ;
	min = mas;
	ft_rec_sort(min, mas + 1, size - 1);
	ft_rec_direct_selection(mas + 1, size - 1);
}

int		main(void)
{
	int	mas[7] = {9, 3, 5, 2, 2, 2, 4};
	int	size = 7;
	int	i = 0;

	ft_rec_direct_selection(mas, 7);
	while(size)
	{
		printf("%d ", mas[i]);
		--size;
		++i;
	}
	return (0);
}