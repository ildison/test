/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:57:03 by cormund           #+#    #+#             */
/*   Updated: 2019/08/14 17:16:52 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft.h"

#define FL_PLAYER_NAME "cormund"

#define check_size(size, x, y) (x >= 0 && y >= 0 && y < size.y && x < size.x)

int fd;

typedef struct		s_pnt
{
	int				y;
	int				x;
}					t_pnt;


typedef struct		s_fl
{
	char			plr_letter;
	char			**board;
	int				**heat_map;
	int				n_piece;
	int				sum_cold;
	t_pnt			size_board;
	t_pnt			size_piece;
	t_pnt			*piece;
	t_pnt			place;
}					t_fl;

void				read_board(t_fl *fl);
void				heat_map(t_fl *fl);
void				sort(t_fl *fl);

#endif