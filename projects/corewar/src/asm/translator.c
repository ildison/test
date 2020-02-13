/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:31:53 by cormund           #+#    #+#             */
/*   Updated: 2020/02/13 11:57:30 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			translate_num(unsigned char **byte_code, int num, int size)
{
	while (size > 0)
	{
		--size;
		**byte_code = ((num >> (8 * size)) & 0xff);
		++(*byte_code);
	}
}

static int			get_type_args(unsigned char *types)
{
	return ((types[0] == T_IND ? IND_CODE : types[0]) << 6 |\
			(types[1] == T_IND ? IND_CODE : types[1]) << 4 |\
			(types[2] == T_IND ? IND_CODE : types[2]) << 2);
}

static void			translate_args(unsigned char **byte_code, t_oper *oper)
{
	int				n_arg;
	int				size_arg;

	n_arg = 0;
	while (n_arg < oper->op->args_num)
	{
		if (oper->args_types[n_arg] == T_REG)
			size_arg = 1;
		else if (oper->args_types[n_arg] == T_IND)
			size_arg = 2;
		else
			size_arg = oper->op->dir_size ? 2 : 4;
		translate_num(byte_code, oper->nums[n_arg], size_arg);
		++n_arg;
	}
}

static void			translate_opers(unsigned char *byte_code, t_oper *oper)
{
	while (oper)
	{
		translate_num(&byte_code, oper->op->code, 1);
		if (oper->op->need_types)
			translate_num(&byte_code, get_type_args(oper->args_types), 1);
		translate_args(&byte_code, oper);
		oper = oper->next;
	}
}

void				translate_in_byte_code(t_champ *champ)
{
	unsigned char	*byte_code;
	unsigned char	*tmp;
	int				fd;
	int				size_byte_code;

	fd = open(champ->file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |\
											S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == ASM_ERROR)
		ERROR(strerror(errno));
	champ->code_size = champ->last_oper->offset + champ->last_oper->size;
	size_byte_code = ASM_MAGIC_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH +\
					ASM_NULL_SIZE * 2 + ASM_CODE_SIZE + champ->code_size;
	byte_code = ft_memalloc(size_byte_code);
	if (!(tmp = byte_code))
		ERROR(strerror(errno));
	translate_num(&tmp, COREWAR_EXEC_MAGIC, ASM_MAGIC_SIZE);
	ft_strncpy((char *)tmp, champ->prog_name, PROG_NAME_LENGTH + ASM_NULL_SIZE);
	tmp += PROG_NAME_LENGTH + ASM_NULL_SIZE;
	translate_num(&tmp, champ->code_size, ASM_CODE_SIZE);
	ft_strncpy((char *)tmp, champ->comment, COMMENT_LENGTH + ASM_NULL_SIZE);
	tmp += COMMENT_LENGTH + ASM_NULL_SIZE;
	translate_opers(tmp, champ->first_oper);
	write(fd, byte_code, size_byte_code);
	free(byte_code);
	close(fd);
}
