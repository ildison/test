/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:20:12 by cormund           #+#    #+#             */
/*   Updated: 2019/12/30 15:05:02 by cormund          ###   ########.fr       */
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
		ASM_INPUT = read_data(argv[1]);
		ASM_DATA = ASM_INPUT;
		clean_comments(ASM_INPUT);
		parsing_champ(champ);
		ft_printf("name: %s\n", champ->prog_name);
		ft_printf("comment: %s\n", champ->comment);
	}
	return(0);
}
