/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:20:12 by cormund           #+#    #+#             */
/*   Updated: 2019/12/24 18:14:51 by cormund          ###   ########.fr       */
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
		champ->input = read_input(argv[1]);
		clean_comments(champ->input);
		parsing_champ(champ, champ->input);
		ft_printf("name: %s\n", champ->prog_name);
		ft_printf("comment: %s\n", champ->comment);
	}
	return(0);
}
