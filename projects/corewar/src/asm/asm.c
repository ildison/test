/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:20:12 by cormund           #+#    #+#             */
/*   Updated: 2019/12/26 12:35:20 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int argc, char **argv)
{
	t_champ	*champ;

	if (argc > 1)
	{
		champ = ft_memalloc(sizeof(t_champ));
		if (!champ)
			error(strerror(errno));
		champ->data = read_data(argv[1]);
		clean_comments(champ->data);
		parsing_champ(champ, champ->data);
		ft_printf("name: %s\n", champ->prog_name);
		ft_printf("comment: %s\n", champ->comment);
	}
	return(0);
}
