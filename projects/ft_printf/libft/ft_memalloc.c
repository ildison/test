/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:24:21 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/18 10:28:11 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p_alloc;

	p_alloc = NULL;
	if (size)
	{
		p_alloc = malloc(size);
		if (!p_alloc)
			return (NULL);
	}
	ft_bzero(p_alloc, size);
	return (p_alloc);
}
