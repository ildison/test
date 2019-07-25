/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:49:18 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/16 10:20:03 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p_dyn;
	size_t			len;
	unsigned int	i;

	p_dyn = NULL;
	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		p_dyn = (char *)malloc((len + 1) * sizeof(char));
		if ((s == NULL) || (p_dyn == NULL))
			return (NULL);
		ft_bzero(p_dyn, len + 1);
		while (s[i])
		{
			p_dyn[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (p_dyn);
}
