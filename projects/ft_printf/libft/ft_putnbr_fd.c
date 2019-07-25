/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:26:11 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/30 09:08:50 by ksharlen         ###   ########.fr       */
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

void			ft_putnbr_fd(int n, int fd)
{
	int		sign;
	int		array_number[10];
	int		i;
	size_t	size;

	if (fd >= 0 && fd < 7169)
	{
		if (!n)
			ft_putchar_fd('0', fd);
		size = ft_size(n);
		i = 0;
		sign = 1;
		if (n < 0)
		{
			sign = -1;
			ft_putchar_fd('-', fd);
		}
		while (n)
		{
			array_number[i++] = n % 10 * (sign);
			n /= 10;
		}
		while (size)
			ft_putchar_fd(array_number[size-- - 1] + '0', fd);
	}
}
