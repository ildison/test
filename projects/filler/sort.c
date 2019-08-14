/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:48:46 by cormund           #+#    #+#             */
/*   Updated: 2019/08/14 18:36:32 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		check_piece(t_fl *fl, int y, int x)
{
	int		n;
	int		sum_cold;
	int		covers;

	n = 0;
	sum_cold = 0;
	covers = 0;
	while (n < fl->n_piece)
	{
		if (fl->heat_map[y + fl->piece[n].y][x + fl->piece[n].x] == -1)
		{
			++covers;
			printf("here\n");
		}
		else if (fl->heat_map[y + fl->piece[n].y][x + fl->piece[n].x] == -2 || covers > 1)
			return ;
		else
			sum_cold += fl->heat_map[y + fl->piece[n].y][x + fl->piece[n].x];
		++n;
	}
	if (sum_cold <= fl->sum_cold && covers == 1)
	{
		fl->sum_cold = sum_cold;
		fl->place.x = x;
		fl->place.y = y;
	}
}

void		sort(t_fl *fl)
{
	int		x;
	int		y;

	fl->sum_cold = __INT_MAX__;
	fl->place.x = 0;
	fl->place.y = 0;
	y = 0;
	while (y <= (fl->size_board.y - fl->size_piece.y))
	{
		x = 0;
		while (x <= (fl->size_board.x - fl->size_piece.x))
		{
			check_piece(fl, y, x);
			++x;
		}
		++y;
	}
}