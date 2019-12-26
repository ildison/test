/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:15:42 by cormund           #+#    #+#             */
/*   Updated: 2019/12/26 12:35:20 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

# define ASM_SIZE_BUF 1024
# define ASM_ERROR -1
# define ASM_END_OF_STR '\0'

typedef struct	s_champ
{
	char		*data;
	char		*prog_name;
	char		*comment;
}				t_champ;

char			*read_data(char *file);
void			clean_comments(char *data);
void			parsing_champ(t_champ *champ, char *data);
void			error_manager(char *error, char *data, char *ptr_error);

#endif
