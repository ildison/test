/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:15:42 by cormund           #+#    #+#             */
/*   Updated: 2020/01/10 15:39:26 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

# define ASM_SIZE_BUF 1024
# define ASM_NOT_OPER 0
# define ASM_END_OF_STR '\0'

# define ASM_ERROR -1

# define ASM_DATA g_data.data
# define ASM_INPUT g_data.input
# define ASM_EOL g_data.eol
struct s_data		g_data;
t_op    op_tab[17];

typedef enum		e_op_code
{
	asm_live = 1,
	asm_ld,
	asm_st,
	asm_add,
	asm_sub,
	asm_and,
	asm_or,
	asm_xor,
	asm_zjmp,
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
	char			*args[3];
	int				size;
	int				offset;
	struct s_oper	*next;
}					t_oper;

typedef struct		s_champ
{
	char			*prog_name;
	char			*comment;
	t_oper			*first_oper;
}					t_champ;

typedef struct		s_data
{
	char			*input;
	char			*data;
	char			*eol;
}					t_data;


char				*read_data(char *file);
void				clean_comments(char *data);
void				parsing_champ(t_champ *champ);
void				error_manager(char *error, unsigned char oper_code);

#endif
