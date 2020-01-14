/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:31:53 by cormund           #+#    #+#             */
/*   Updated: 2020/01/14 15:32:36 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		translate_in_byte_code(t_champ *champ)
{
	int		fd;

	fd = open(champ->file_name, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, S_IWRITE);
	if (fd == -1)
		error(strerror(errno));
	
	close (fd);
}
