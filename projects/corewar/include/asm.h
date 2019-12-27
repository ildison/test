/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:15:42 by cormund           #+#    #+#             */
/*   Updated: 2019/12/27 16:40:30 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

# define ASM_SIZE_BUF 1024
# define ASM_ERROR -1
# define ASM_END_OF_STR '\0'

typedef enum		e_op_code
{
	asm_live,
	asm_ld,
	asm_st,
	asm_add,
	asm_sub,
	asm_and,
	asm_or,
	asm_xor,
	asm_zimp,
	asm_ldi,
	asm_sti,
	asm_fork,
	asm_lld,
	asm_lldi,
	asm_lfork,
	asm_aff
}					t_op_code;

typedef struct		s_arg
{
	char			*first;
	char			*second;
	char			*third;
}					t_arg;

typedef struct		s_label
{
	char			*name;
	int				offset;
	struct s_label	*next;
}					t_label;

typedef struct		s_oper
{
	t_op_code		op_code;
	int				size;
	int				offset;
	struct s_oper	*next;
}					t_oper;

typedef struct		s_champ
{
	char			*data;
	char			*prog_name;
	char			*comment;
}					t_champ;

char				*read_data(char *file);
void				clean_comments(char *data);
void				parsing_champ(t_champ *champ, char *data);
void				error_manager(char *error, char *data, char *ptr_error);

#endif
