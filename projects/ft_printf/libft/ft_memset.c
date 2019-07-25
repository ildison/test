/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:30:30 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/15 14:55:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int value, size_t num)
{
	size_t	byte_shift;

	byte_shift = 0;
	while (byte_shift < num)
		*((unsigned char *)buf + byte_shift++) = (int)value;
	return (buf);
}
