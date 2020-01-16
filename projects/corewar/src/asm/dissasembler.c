/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dissasembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:48:28 by cormund           #+#    #+#             */
/*   Updated: 2020/01/16 10:11:05 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static		write_asm_opers(void)
// {
	
// }

int			get_number(int size)
{
	int		num;
	int		shift;

	num = 0;
	shift = 8 * size;
	while (shift)
	{
		shift -= 8;
		num |= (((int)*(ASM_DATA++) & 0xff) << shift);
	}
	return (num);
}

void		dissasembler(t_champ *champ)
{
	// int		fd;
	int		code_size;

	// fd = open(champ->file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |\
	// 										S_IWUSR | S_IRGRP | S_IROTH);
	// if (fd == ASM_ERROR)
	// 	error(strerror(errno));
	ft_printf(".name		\"%s\"\n", ASM_DATA + ASM_MAGIC_SIZE);
	ASM_DATA += PROG_NAME_LENGTH + ASM_NULL_SIZE + ASM_MAGIC_SIZE;
	code_size = get_number(4);
	ft_printf("size = %d\n", code_size);
	ft_printf(".comment	\"%s\"\n", ASM_DATA);
	ASM_DATA += COMMENT_LENGTH + ASM_NULL_SIZE;
	// write_asm_opers();
	// close(fd);
}
