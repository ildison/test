/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:15:42 by cormund           #+#    #+#             */
/*   Updated: 2019/12/24 10:53:48 by cormund          ###   ########.fr       */
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
	char		*input;
	
}				t_champ;

char			*read_input(char *file);
void			clean_comments(char *input);

#endif
