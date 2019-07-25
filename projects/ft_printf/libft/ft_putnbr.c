/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:35:07 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/23 11:33:41 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t size;

	if (!n)
		return (0);
	size = 0;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

void			ft_putnbr(int n)
{
	int		sign;
	int		array_number[10];
	int		i;
	size_t	size;

	if (!n)
		ft_putchar('0');
	size = ft_size(n);
	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	while (n)
	{
		array_number[i++] = n % 10 * (sign);
		n /= 10;
	}
	while (size)
		ft_putchar(array_number[size-- - 1] + '0');
}
