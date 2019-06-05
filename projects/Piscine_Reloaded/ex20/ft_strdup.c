/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:29:26 by cormund           #+#    #+#             */
/*   Updated: 2019/04/03 18:12:25 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	int		i;
	char	*dub;

	dub = (char *)malloc(sizeof(src));
	if (dub == (void*)0)
		return (src);
	i = 0;
	while (src[i] != '\0')
	{
		dub[i] = src[i];
		i++;
	}
	dub[i] = '\0';
	return (dub);
}
