/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2xmas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:49:08 by cormund           #+#    #+#             */
/*   Updated: 2019/11/05 16:16:42 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_2x_mas(void **mas)
{
	void	**tmp;

	if ((tmp = mas))
	{
		while (*mas)
		{
			free(*mas);
			++mas;
		}
		free(tmp);
	}
}
