/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:57:03 by cormund           #+#    #+#             */
/*   Updated: 2019/08/12 20:40:24 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft.h"

#define FL_PLAYER_NAME "cormund"
#define FL_BUF_SIZE 256

typedef struct		s_fl
{
	char			plr_letter;
	int				n_col;
	int				n_lines;
	char			**board;
}					t_fl;

void				read_board(t_fl *fl);

#endif