/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:20:12 by cormund           #+#    #+#             */
/*   Updated: 2020/01/14 17:07:05 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*new_filename(char *file)
{
	char	*new;
	int		len_file;

	len_file = ft_strlen(file);
	new = ft_strnew(len_file + 2);
	if (!new)
		error(strerror(errno));
	ft_strncpy(new, file, len_file - 1);
	ft_strcat(new, "cor");
	return (new);
}

int			main(int argc, char **argv)
{
	t_champ	*champ;

	if (argc > 1)
	{
		champ = ft_memalloc(sizeof(t_champ));
		if (!champ)
			error(strerror(errno));
		champ->file_name = new_filename(argv[1]);
		ASM_INPUT = read_data(argv[1]);
		ASM_EOL = NULL;
		clean_comments(ASM_INPUT);
		parsing_champ(champ);
		translate_in_byte_code(champ);
	}
	return(0);
}
