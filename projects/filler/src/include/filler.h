/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:57:03 by cormund           #+#    #+#             */
/*   Updated: 2019/09/09 17:58:49 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define FL_PLAYER_NAME "cormund"
# define FL_FD 0

# define check_size(size, x, y) (x >= 0 && y >= 0 && y < size.y && x < size.x)

typedef struct		s_pnt
{
	short				y;
	short				x;
}					t_pnt;


typedef struct		s_fl
{
	char			plr;
	int				**heat_map;
	int				n_piece;
	int				sum_cold;
	t_pnt			size_board;
	t_pnt			size_piece;
	t_pnt			*piece;
	t_pnt			place;
	t_pnt			begin;
	short			fl_exit;
}					t_fl;

void				read_board(t_fl *fl);
void				prep_heat_map(t_fl *fl, char *line, int y);
void				heat_map(t_fl *fl);
void				sort(t_fl *fl);

#endif