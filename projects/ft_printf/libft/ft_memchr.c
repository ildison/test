/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:57:51 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/21 16:03:07 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	byte_shift;
	void	*p_str;
	short	flag_find;

	flag_find = 0;
	byte_shift = 0;
	while (byte_shift < n)
	{
		if (*((unsigned char *)s + byte_shift) == (unsigned char)c)
		{
			p_str = ((unsigned char *)s + byte_shift);
			byte_shift = n;
			flag_find = 1;
		}
		else
			++byte_shift;
	}
	if (!flag_find)
		return (NULL);
	return (p_str);
}
