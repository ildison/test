/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:15:42 by cormund           #+#    #+#             */
/*   Updated: 2020/01/14 09:39:17 by cormund          ###   ########.fr       */
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
# define ASM_ERR_ENDLINE "Syntax error: ENDLINE"
# define ASM_ERR_WRONG_TITLE "Syntax error: wrong title"
# define ASM_ERR_LEXICAL "Lexical error at"
# define ASM_ERR_INVALID_PARAM "Invalid parameter count for instruction"
# define ASM_ERR_WRONG_TYPE "Syntax error: wrong type for instruction"
# define ASM_ERR_WRONG_LABEL "Syntax error: wrong label"

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

typedef union		u_args_types
{
	unsigned char	code_types;
	struct
	{
		uint8_t		nan:2;
		uint8_t		third:2;
		uint8_t		second:2;
		uint8_t		first:2;
	}				types;
}					t_args_types;

typedef struct		s_oper
{
	t_op_code		code;
	char			*args[3];
	unsigned char	args_types[3];
	unsigned char	code_types;
	int				size;
	int				offset;
	struct s_oper	*next;
	struct s_oper	*prev;
}					t_oper;

typedef struct		s_champ
{
	char			*prog_name;
	char			*comment;
	t_oper			*first_oper;
	t_oper			*last_oper;
	t_label			*label;
}					t_champ;

typedef struct		s_data
{
	char			*input;
	char			*data;
	char			*eol;
}					t_data;


char				*read_data(char *file);
void				clean_comments(char *data);
char				*skip_spaces();
void				parsing_champ(t_champ *champ);
void				pars_header(t_champ *champ);
void				pars_opers(t_champ *champ);
void				pars_args(t_oper *oper);
void				check_number(char *s);
void				check_label(char *label);
int					is_label(char *data);
t_label				*new_label(int len_label);
void				add_new_label(t_champ *champ, t_label *label);
int					set_offset(t_champ *champ);
void				validation_args_types(t_oper *oper);
void				error_manager(char *error, unsigned char oper_code);

#endif
