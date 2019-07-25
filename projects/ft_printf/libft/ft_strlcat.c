/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:02:52 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/15 14:45:09 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	int		size_all;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (ft_strlen(src) + size);
	size_all = size - len_dst;
	while (*dst)
		dst++;
	while ((*dst++ = *src++) && ((size_all - 1) > 0))
		--size_all;
	*(dst - 1) = '\0';
	return (len_src + len_dst);
}
