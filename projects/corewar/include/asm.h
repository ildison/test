/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:15:42 by cormund           #+#    #+#             */
/*   Updated: 2020/02/13 12:01:40 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "op.h"

# define ERROR ft_error_exit

# define ASM_SIZE_BUF 1024
# define ASM_NOT_OPER 0
# define ASM_NOT_LABEL 0
# define ASM_END_OF_STR '\0'

# define ASM_MAGIC_SIZE 4
# define ASM_NULL_SIZE 4
# define ASM_CODE_SIZE 4

# define ASM_ERROR -1
# define ASM_ERR_ENDLINE "Syntax error: ENDLINE"
# define ASM_ERR_WRONG_TITLE "Syntax error: wrong title"
# define ASM_ERR_LEXICAL "Lexical error at"
# define ASM_ERR_INVALID_PARAM "Invalid parameter count for instruction"
# define ASM_ERR_WRONG_TYPE "Syntax error: wrong type for instruction"
# define ASM_ERR_WRONG_LABEL "Syntax error: wrong label"
# define ASM_ERR_END "Syntax error: END"
# define ASM_ERR_REG_VALUE "Syntax error: wrong registry value"
# define ASM_ERR_WRONG_FILENAME "Wrong filename (need .s or .cor with -d flag)"

# define ASM_DISASM_OPTION 'd'
# define ASM_HELP_OPTION 'h'
# define ASM_ON_DISSASM_OPTION 1

struct s_data		g_data;
t_op				g_op_tab[17];

typedef struct		s_label
{
	char			*name;
	int				offset;
	struct s_label	*next;
}					t_label;

typedef struct		s_oper
{
	t_op			*op;
	unsigned char	args_types[3];
	unsigned char	code_types;
	char			*args[3];
	int				nums[3];
	int				size;
	int				offset;
	struct s_oper	*next;
}					t_oper;

typedef struct		s_champ
{
	char			*file_name;
	char			*prog_name;
	char			*comment;
	t_oper			*first_oper;
	t_oper			*last_oper;
	t_label			*label;
	int				code_size;
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
void				replace_args2numbers(t_champ *champ);
void				error_manager(char *error, t_op *wrong_oper,\
												char *wrong_label);
void				translate_in_byte_code(t_champ *champ);
void				check_options(int argc, char **argv, char *flag);
void				clean_up(t_champ *champ);
void				dissasembler(t_champ *champ);

#endif
