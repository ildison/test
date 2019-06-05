/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:15:33 by cormund           #+#    #+#             */
/*   Updated: 2019/04/23 14:16:25 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char *a, char *b, size_t n)
{
	char	*buf;
	char	*fresh;

	fresh = NULL;
	if ((buf = ft_strndup(b, n)))
	{
		fresh = ft_strjoin(a, buf);
		ft_strdel(&buf);
	}
	return (fresh);
}
