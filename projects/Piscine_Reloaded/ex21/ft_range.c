/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:01:02 by cormund           #+#    #+#             */
/*   Updated: 2019/04/04 10:04:54 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ofint;
	int i;

	if (min >= max)
		return ((void*)0);
	if ((ofint = (int *)malloc(sizeof(int) * (max - min))) == (void*)0)
		return ((void*)0);
	i = 0;
	while (i < (max - min))
	{
		ofint[i] = min + i;
		i++;
	}
	return (ofint);
}
