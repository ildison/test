/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 07:10:40 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/16 10:17:52 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	len;
	size_t	i;

	new_str = NULL;
	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		new_str = (char *)malloc((len + 1) * sizeof(char));
		if (new_str == NULL)
			return (NULL);
		ft_bzero(new_str, len + 1);
		while (s[i] != '\0')
		{
			new_str[i] = (*f)(s[i]);
			i++;
		}
	}
	return (new_str);
}
