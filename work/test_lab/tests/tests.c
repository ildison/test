/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:14:14 by cormund           #+#    #+#             */
/*   Updated: 2019/08/13 14:53:24 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char		*f_strstr(const char *haystack, const char *needle)
{
	size_t	len_hay;
	size_t	len_nee;

	if (!*(needle))
		return ((char*)haystack);
	len_hay = ft_strlen(haystack);
	len_nee = ft_strlen(needle);
	while (*haystack && len_nee <= len_hay)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, len_nee) == 0)
			return ((char*)haystack);
		haystack++;
		len_hay--;
	}
	return ((void*)0);
}

int		main(int ac, char **av)
{
	char *s;
	s = f_strstr("cormund.", "cormund");
	printf("%p\n", s);
	return (0);
}