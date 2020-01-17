/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dissasembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:48:28 by cormund           #+#    #+#             */
/*   Updated: 2020/01/17 12:42:25 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			get_number(int size)
{
	int				num;
	int				shift;

	num = 0;
	shift = 8 * size;
	while (shift)
	{
		shift -= 8;
		num |= (((int)*(ASM_DATA++) & 0xff) << shift);
	}
	return (num);
}

static void			print_args(int op_code, int fd)
{
	unsigned char	code_types;
	int				shift;
	int				n_arg;

	shift = 6;
	code_types = (unsigned char)get_number(1);
	n_arg = g_op_tab[op_code - 1].args_num;
	while (n_arg--)
	{
		if (((code_types >> shift) & 0x3) == REG_CODE)
			ft_printf("%vr%hhd%s", fd, get_number(1), n_arg ? ", " : "\n");
		else if (((code_types >> shift) & 0x3) == IND_CODE)
			ft_printf("%v%hd%s", fd, get_number(2), n_arg ? ", " : "\n");
		else if (g_op_tab[op_code - 1].dir_size)
			ft_printf("%v%%%hd%s", fd, get_number(2), n_arg ? ", " : "\n");
		else
			ft_printf("%v%%%d%s", fd, get_number(4), n_arg ? ", " : "\n");
		shift -= 2;
	}
}

static void			print_asm_opers(char *end, int fd)
{
	int				op_code;

	while (ASM_DATA < end)
	{
		op_code = get_number(1);
		ft_printf("%v%s		", fd, g_op_tab[op_code - 1].name);
		if (g_op_tab[op_code - 1].need_types)
			print_args(op_code, fd);
		else if (g_op_tab[op_code - 1].dir_size)
			ft_printf("%v%%%hd\n", fd, get_number(2));
		else
			ft_printf("%v%%%d\n", fd, get_number(4));
	}
}

void				dissasembler(t_champ *champ)
{
	int				fd;
	int				code_size;

	fd = open(champ->file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |\
											S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == ASM_ERROR)
		error(strerror(errno));
	ft_printf("%v.name		\"%s\"\n", fd, ASM_DATA + ASM_MAGIC_SIZE);
	ASM_DATA += PROG_NAME_LENGTH + ASM_NULL_SIZE + ASM_MAGIC_SIZE;
	code_size = get_number(4);
	ft_printf("%v.comment	\"%s\"\n\n", fd, ASM_DATA);
	ASM_DATA += COMMENT_LENGTH + ASM_NULL_SIZE;
	print_asm_opers(ASM_DATA + code_size, fd);
	close(fd);
}
