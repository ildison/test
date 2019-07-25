/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:04:17 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/23 15:55:22 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *p_alloc;

	p_alloc = NULL;
	p_alloc = (char *)malloc((size + 1) * sizeof(char));
	if (p_alloc == NULL)
		return (NULL);
	ft_bzero(p_alloc, size + 1);
	return (p_alloc);
}
