/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:03:31 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/22 13:23:32 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int			len;
	char		*p_str;
	size_t		i;

	i = 0;
	p_str = dest;
	len = ft_strlen(dest);
	dest += len;
	while ((*dest = *src) && n--)
	{
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (p_str);
}
