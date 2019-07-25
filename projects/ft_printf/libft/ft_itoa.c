/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 08:43:03 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/30 08:43:18 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_number_digit(int n)
{
	size_t	sum;

	if (!n)
		return (1);
	sum = 0;
	while (n != 0)
	{
		sum++;
		n /= 10;
	}
	return (sum);
}

static void			ft_input_digit(char *p_dyn, size_t size, int n)
{
	short	sign;

	sign = n < 0 ? -1 : 1;
	if (sign < 0)
	{
		p_dyn[0] = '-';
		size += 1;
	}
	while (size)
	{
		p_dyn[size-- - 1] = (n % 10 * (sign)) + '0';
		n /= 10;
		if (size == 1 && sign < 0)
			size = 0;
	}
}

char				*ft_itoa(int n)
{
	size_t	size;
	char	*p_dyn;
	short	sign_for_alloc;

	sign_for_alloc = n < 0 ? 1 : 0;
	size = ft_number_digit(n);
	if (!(p_dyn = ft_strnew(size + sign_for_alloc)))
		return (NULL);
	ft_input_digit(p_dyn, size, n);
	return (p_dyn);
}
